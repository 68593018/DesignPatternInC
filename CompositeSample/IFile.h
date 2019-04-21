
#ifndef IFILE_H
#define IFILE_H

typedef struct IFile IFile;

struct IFile
{
	void *pImplicit;

    /* 
     * ��ӣ�ֻ�ǰ�һ��IFile��ӵ���ǰIFile�У�
     * ��û�а�����ϵ��ֻ��һ����֯��ϵ��
     * ��ˣ�ֻ��������á�
     * ��Ȼ���԰���Ҫ����IFile��ʵ�������ö����
     * ֻ����Ҫ����һ�ִ���ʵ�ֶ���. */
	void (* Add)(IFile *pFile, IFile *pAdd);

    /*
     * ��������ƣ��Ƴ�ֻ�ǽ��������֯��ϵ���ѣ�
     * ��û�����ٶ��� */
	void (* Remove)(IFile *pFile, IFile *pRmv);

    /* 
     * ��ȡ���ļ�ָ�롣
     * ����ΪC-Style����0��ʼ */
	IFile *(* GetChild)(IFile *pFile, int nIndex);

    /* ������ҵ���߼��ķ���������ģ��һ��ɱ������ */
	void (* KillVirus)(IFile *pFile);

	void (* Free)(IFile **ppFile);
};

#endif // !IFILE_H
