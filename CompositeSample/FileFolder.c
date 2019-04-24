
#include <stdio.h>
#include <apr_ring.h>
#include <apr_strings.h>
#include <apr_ring_ext.h>
#include "FileFolder.h"

/* 
 * ˽�����ͣ����ڲ�ʹ��
 * IFile����˫��������
 */
GENERIC_RING(IFile)

//���ԡ���������

struct FileFolder_Fld
{
	//��ʵ��ר���ڴ��
	apr_pool_t *m_pPool;

	//�̳нӿ�
	IFile m_file;

    //�ļ�������
    char *m_pName;

    //���ļ��С��ļ�����
	RING(IFile) *m_pFiles;
};

//��˽�з���
/* ��ָ���װ�����Ӧ�������͵�Ԫ������ */
static RING_ELEM(IFile) *ConstructRingElement(apr_pool_t *pPool, IFile *pFile)
{
    RING_ELEM(IFile) *pElem = /* (RING_ELEM(IFile) *) */apr_palloc(pPool, sizeof(RING_ELEM(IFile)));
    pElem->pInst = pFile;
    return pElem;
}

//˽�з���
/* �����������Ƿ���ڸ�����Ԫ�أ�������ڣ��򷵻�Ԫ�ص�ָ�� */
static int FindElement(RING(IFile) *pRing, RING_ELEM(IFile) *pToFind)
{
    int nIndex = 0;
    RING_ELEM(IFile) *pIterate;
    for (pIterate = APR_RING_FIRST(pRing); pIterate != APR_RING_SENTINEL(pRing, RING_ELEM(IFile), RING_LINK); pIterate = APR_RING_NEXT(pIterate, RING_LINK))
    {
        nIndex++;

        if (pIterate == pToFind)
        {
            //�����д��ڸ�Ԫ�أ�
            return nIndex;
        }
    }

    //�����в����ڸ�Ԫ��
    return nIndex = -1;
}

//ʵ�ֽӿڷ���
static void Free(IFile **ppFile)
{
	FileFolder_Free(&(FileFolder *)(*ppFile)->pImplicit);
	*ppFile = NULL;
}

//ʵ�ֽӿڷ���
static void Add(IFile *pFile, IFile *pAdd)
{
	FileFolder *pInst = (FileFolder *)pFile->pImplicit;

    int nIndex = 0;
    RING_ELEM(IFile) *pElem = ConstructRingElement(pInst->pFld->m_pPool, pAdd);
    if (FindElement(pInst->pFld->m_pFiles, pElem) != -1)
    {
        //������ڸ�Ԫ�أ������
        puts("�Ѿ����ڸ�Ԫ�أ���������ӡ�");
    }
    else
    {
        APR_RING_INSERT_TAIL(pInst->pFld->m_pFiles, pElem, RING_ELEM(IFile), RING_LINK);
        puts("��ӳɹ���");
    }
}

//�Ƴ�Ԫ��
static void Remove(IFile *pFile, IFile *pRmv)
{
	FileFolder *pInst = (FileFolder *)pFile->pImplicit;

    RING_ELEM(IFile) *pElem = ConstructRingElement(pInst->pFld->m_pPool, pRmv);

    if (FindElement(pInst->pFld->m_pFiles, pElem) != -1)
    {
        //�ҵ���Ԫ��
		APR_RING_REMOVE(pElem, RING_LINK);
        puts("�ҵ���ɾ����ָ����Ԫ��");
    }
    else
    {
        puts("ûҪ�ҵ�ָ������Ҫɾ����Ԫ�ء�");
    }
}

static IFile *GetChild(IFile *pFile, int nIndex)
{
	FileFolder *pInst = (FileFolder *)pFile->pImplicit;

    int nI = 0;
    RING_ELEM(IFile) *pIterate;
    for (pIterate = APR_RING_FIRST(pInst->pFld->m_pFiles); pIterate != APR_RING_SENTINEL(pInst->pFld->m_pFiles, RING_ELEM(IFile), RING_LINK); pIterate = APR_RING_NEXT(pIterate, RING_LINK))
    {
        if (nI == nIndex)
        {
            return pIterate->pInst;
        }
    }

    return NULL;
}

static void KillVirus(IFile *pFile)
{
	FileFolder *pInst = (FileFolder *)pFile->pImplicit;
    //ģ��ɱ��
    printf("���ļ���%s����ɱ��.\n", pInst->pFld->m_pName);

    RING_ELEM(IFile) *pIterate;
    for (pIterate = APR_RING_FIRST(pInst->pFld->m_pFiles); pIterate != APR_RING_SENTINEL(pInst->pFld->m_pFiles, RING_ELEM(IFile), RING_LINK); pIterate = APR_RING_NEXT(pIterate, RING_LINK))
    {
        //�������ļ��С��ļ�������ɱ��
        pIterate->pInst->KillVirus(pIterate->pInst);
    }
}

FileFolder * FileFolder_New(apr_pool_t * pSupPool, const char *const pName)
{
	apr_pool_t *pPool;
	apr_pool_create(&pPool, pSupPool);

	FileFolder *pInst = apr_palloc(pPool, sizeof(FileFolder));

	pInst->pFld = apr_palloc(pPool, sizeof(FileFolder_Fld));
	pInst->pFld->m_pPool = pPool;
	pInst->pFld->m_file.pImplicit = pInst;
	pInst->pFld->m_file.Free = Free;

    pInst->pFld->m_pName = apr_pstrdup(pInst->pFld->m_pPool, pName);
	pInst->pFld->m_pFiles = apr_palloc(pInst->pFld->m_pPool, sizeof(RING(IFile)));
	/*��ʼ����*/
	APR_RING_INIT(pInst->pFld->m_pFiles, RING_ELEM(IFile), RING_LINK);

    pInst->pFld->m_file.Add = Add;
    pInst->pFld->m_file.Remove = Remove;
    pInst->pFld->m_file.GetChild = GetChild;
    pInst->pFld->m_file.KillVirus = KillVirus;

	return pInst;
}

IFile * FileFolder2IFile(FileFolder * pInst)
{
    return &(pInst->pFld->m_file);
}

void FileFolder_Free(FileFolder ** ppInst)
{
	apr_pool_destroy((*ppInst)->pFld->m_pPool);

	*ppInst = NULL;
}
