
#include <stdio.h>
#include <apr_pools.h>
#include "IFile.h"
#include "FileFolder.h"
#include "FileImage.h"
#include "FileText.h"
#include "FileVideo.h"

int main(int argc, char **argv)
{
    apr_pool_t *pMemPool;

    apr_initialize();

    apr_pool_create(&pMemPool, NULL);

    IFile *pFile1, *pFile2, *pFile3, *pFile4, *pFile5;
    IFile *pFolder1, *pFolder2, *pFolder3, *pFolder4;

    pFolder1 = FileFolder2IFile(FileFolder_New(pMemPool, "�ҵ�����"));
    pFolder2 = FileFolder2IFile(FileFolder_New(pMemPool, "ͼ���ļ���"));
    pFolder3 = FileFolder2IFile(FileFolder_New(pMemPool, "�ı��ļ���"));
    pFolder4 = FileFolder2IFile(FileFolder_New(pMemPool, "��Ƶ�ļ���"));

    pFile1 = FileImage2IFile(FileImage_New(pMemPool, "С��Ů.jpg"));
    pFile2 = FileImage2IFile(FileImage_New(pMemPool, "���޼�.gif"));
    pFile3 = FileText2IFile(FileText_New(pMemPool, "�����澭.txt"));
    pFile4 = FileText2IFile(FileText_New(pMemPool, "��������.doc"));
    pFile5 = FileVideo2IFile(FileVideo_New(pMemPool, "�������.rmvb"));

    pFolder2->Add(pFolder2, pFile1);
    pFolder2->Add(pFolder2, pFile2);
    pFolder3->Add(pFolder3, pFile3);
    pFolder3->Add(pFolder3, pFile4);
    pFolder4->Add(pFolder4, pFile5);
    pFolder1->Add(pFolder1, pFolder2);
    pFolder1->Add(pFolder1, pFolder3);
    pFolder1->Add(pFolder1, pFolder4);

    //�ӡ��ҵ����ϡ��ڵ㿪ʼ����ɱ������
    pFolder1->KillVirus(pFolder1);

    apr_pool_destroy(pMemPool);

    apr_terminate();

    return EXIT_SUCCESS;
}