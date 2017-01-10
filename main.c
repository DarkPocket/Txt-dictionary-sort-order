// 使用dirent.h头文件中声明的opendir(),readdir()函数；
// 读取文件夹的文件，备份文件名至txt中（无
// 按格式排列 // 排序？

//add_list(pHead, pNew); 效率过低
//准备重写

/*2016 12 24
//添加尾节点 添加节点效率增加数倍
//目录读取字典文件 单个排序输出 完成
删除多余注释代码


输出文件位置和文件名暂未完成


*/


#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<windows.h>


#include"linkList.h"

#include <errno.h>

#define ARRAY_SIZE  1000000


int t = 0;


int  SeparateDicLongOrShort (   char  FileNameCach[MAX_PATH]);

int GetDirFileName ( char dir_name[MAX_PATH], char dir_out[MAX_PATH] ) ;

void getFileExten( char cFileName[ MAX_PATH ] , char Exten[MAX_PATH / 10 ]);
int compare11(const void *a, const void *b);

int DicTxtSort2 ( char  FileNameIn[MAX_PATH] ,  char  dir_name[MAX_PATH], char FileName [MAX_PATH]  );
int  SeparateDicToThree (   char  FilePathNameCach[MAX_PATH], char  dir_name[MAX_PATH], char FileName [MAX_PATH]  );
int memu(  );
int DicCombine( char  FileNameA[MAX_PATH] , char  FileNameB[MAX_PATH]  , char  FileNameC[MAX_PATH]  );



int  SeparateDicLongOrShort (   char  FileNameCach[MAX_PATH])
{
        //将字典密码按长度分开 ，len<8 或者 len >8

        int MinLen = 8;
        int MaxLen = N; //20


        char TxtFileName[MAX_PATH] = { 0 };
        char  FileName[MAX_PATH] = { 0 }, FileName2[MAX_PATH] = { 0 };
        char Word[MAX_PATH] = { 0 };

        FILE *fp, *wreitFp, *wreitFp2;

        int wordMaxLen = 0, wordLenCah = 0;
        int shorLen = 0;
        long int  wordCount = 0;
        int i = 0, j = 0;


        strcpy(TxtFileName, FileNameCach);
        printf("\n 文件=%s\n", TxtFileName);
        // 打开文件
        if ((fp = fopen(TxtFileName, "r")) == NULL)
        {
                printf("%s open error !\n", TxtFileName);
                // exit(-1);
                return -1;
                //return NULL;
        }

        //分开的字典

        i = 0;
        j = strlen( TxtFileName);

        do
        {
                FileName[i] = TxtFileName[i];
                i++;
        }
        while (i < j - 4);


        strcat(FileName, "-1.txt");
        printf("  file opening  %s \n ", FileName);

        if ((wreitFp = fopen(FileName, "a+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileName);
        }



        i = 0;
        while ( TxtFileName[i] != '.')
        {
                FileName2[i] = TxtFileName[i];
                i++;
        };

        strcat(FileName2, "-short.txt");
        printf("  file opening  %s \n ", FileName2);

        if ((wreitFp2 = fopen(FileName2, "a+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileName2);
        }


        rewind(fp);

        while (!feof(fp))
        {
                fscanf(fp, "%s", Word);


                wordLenCah = strlen(Word);
                if (wordMaxLen  < wordLenCah)
                {
                        wordMaxLen = wordLenCah;
                }

                if ((wordLenCah < 8))
                {
                        shorLen++;
                        fprintf(wreitFp2, "%s\n", Word);


                }
                else
                {
                        fprintf(wreitFp, "%s\n", Word);

                }
                wordCount++;


                if (wordLenCah > N - 2)
                {
                        printf("字符串长度可能过长\n %s \n", Word);
                }

                strcpy(Word, "");
        }


        printf(" 最长 %d  \n", wordMaxLen);
        printf("  %d 个短密码 \n", shorLen);
        printf(" 共 %ld 个密码 \n", wordCount);

        if ( fclose(wreitFp))
        {
                printf("Error  file close ! %s \n ", FileName);
        }
        if ( fclose(wreitFp2))
        {
                printf("Error file close  %s  \n ", FileName2);
        }
        if ( fclose(fp))
        {
                printf("Error file close  %s  \n ", TxtFileName);
        }
        return 0;

}

//int  SeparateDicToThree (   char  FileNameCach[MAX_PATH], char  FileMiddlePath[MAX_PATH], char  FileShortPath[MAX_PATH], char  FileTolongPath[MAX_PATH])

int  SeparateDicToThree (   char  FilePathNameCach[MAX_PATH], char  dir_name[MAX_PATH], char FileName [MAX_PATH]  )
{
        //将字典密码按长度分开 ，len<8   8 -  N  (20)   或者 len >N
        //分成三部分 短密码 中等长度 过长的

        int MinLen = 8;
        int MaxLen = N; //20


        char TxtFileName[MAX_PATH] = { 0 };
        char  FileShort[MAX_PATH] = { 0 };
        char FileMiddle[MAX_PATH] = { 0 };
        char FileToolong[MAX_PATH] = { 0 };

        char Word[MAX_PATH] = { 0 };

        FILE *fp, *wreitFp, *wreitFp2, * wreitFpLong;

        int wordMaxLen = 0, wordLenCah = 0;
        int shorLen = 0;
        long int  wordCount = 0;
        int i = 0, j = 0;


        //   strcat(dir_name, "\\");
        char  FileMiddlePath[MAX_PATH] = { 0 };
        char  FileShortPath[MAX_PATH] = { 0 };
        char  FileToolongPath[MAX_PATH] = { 0 };

        sprintf(  FileShortPath, "%s\\Short", dir_name);
        sprintf(  FileMiddlePath, "%s\\Middle", dir_name);
        sprintf(  FileToolongPath, "%s\\Toolong", dir_name);



        if (access(FileShortPath, 0)) //判断目录是否存在
        {
                printf("文件夹不存在！");

                if (_mkdir(FileShortPath) == 0)
                {
                        printf("创建成功！");
                }
                _mkdir(FileMiddlePath);
                _mkdir(FileToolongPath);
                //    _mkdir(FileShortPath);
                //    _mkdir(FileMiddlePath);
                //   _mkdir(FileTolongPath);
        }
        else
        {

        }





        sprintf(  FileShort, "%s\\%s", FileShortPath, FileName);
        sprintf(  FileMiddle, "%s\\%s", FileMiddlePath, FileName);
        sprintf(  FileToolong, "%s\\%s", FileToolongPath, FileName);

        /*
                printf("\n debug 文件=\n%s\n", FileShort);
                 printf("%s open error !\n", FileName);

                return 0;
           //     _mkdir("test");


        */

        strcpy(TxtFileName, FilePathNameCach);
        printf("\n 文件=%s\n", TxtFileName);
        // 打开文件
        if ((fp = fopen(TxtFileName, "r")) == NULL)
        {
                printf("%s open error !\n", TxtFileName);
                // exit(-1);
                return -1;
                //return NULL;
        }

        //分开的字典
        /*
                i = 0;
                j = strlen( TxtFileName);

                do
                {
                        FileMiddle[i] = TxtFileName[i];
                        i++;
                }
                while (i < j - 4);


                strcat(FileMiddle, "-lessen.txt");
                */
        printf("  file opening  %s \n ", FileMiddle);

        if ((wreitFp = fopen(FileMiddle, "a+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileMiddle);
        }


        /*
                i = 0;
                while ( TxtFileName[i] != '.')
                {
                        FileShort[i] = TxtFileName[i];
                        i++;
                };

                strcat(FileShort, "-short.txt");*/
        printf("  file opening  %s \n ", FileShort);

        if ((wreitFp2 = fopen(FileShort, "a+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileShort);
        }

        /*
                i = 0;
                while ( TxtFileName[i] != '.')
                {
                        FileToolong[i] = TxtFileName[i];
                        i++;
                };

                strcat(FileToolong, "-long.txt");
                */
        printf("  file opening  %s \n ", FileToolong);

        if ((wreitFpLong = fopen(FileToolong, "a+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileToolong);
        }

        //  FileNametolong


        rewind(fp);

        while (!feof(fp))
        {
                fscanf(fp, "%s", Word);


                wordLenCah = strlen(Word);
                if (wordMaxLen  < wordLenCah)
                {
                        wordMaxLen = wordLenCah;
                }

                if ((wordLenCah < 8))
                {
                        shorLen++;
                        fprintf(wreitFp2, "%s\n", Word);


                }
                else
                {
                        if (wordLenCah > N)
                        {
                                fprintf(wreitFpLong, "%s\n", Word);
                        }
                        else
                        {
                                fprintf(wreitFp, "%s\n", Word);
                        }


                }
                wordCount++;


                if (wordLenCah > N - 2)
                {
                        printf("字符串长度可能过长\n %s \n", Word);
                }

                strcpy(Word, "");
        }


        printf(" 最长 %d  \n", wordMaxLen);
        printf("  %d 个短密码 \n", shorLen);
        printf(" 共 %ld 个密码 \n", wordCount);

        if ( fclose(wreitFp))
        {
                printf("Error  file close ! %s \n ", FileMiddle);
        }
        if ( fclose(wreitFp2))
        {
                printf("Error file close  %s  \n ", FileShort);
        }

        if ( fclose(wreitFpLong))
        {
                printf("Error file close  %s  \n ", FileToolong);
        }

        if ( fclose(fp))
        {
                printf("Error file close  %s  \n ", TxtFileName);
        }
        return 0;

}


int GetDirFileName (   char dir_name[MAX_PATH], char dir_out[MAX_PATH] )
{
        //遍历文件夹 得到文件名字
        DIR *directory_pointer;
        struct dirent *entry;
        int i;
        FILE *fp;
        char   file_cache[MAX_PATH] = { 0 };
        char   dir_outcache[MAX_PATH] = { 0 };;

        //  strcpy(dir_name, "G:\\软件包\\跑wifi\\beini密码");
        //   strcpy(dir_out, "G:\\软件包\\跑wifi\\1");


        //    strcpy(dir_name, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\测试的字典");

        //    strcpy(dir_out, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\排序结果");




        strcpy(file_cache, dir_name);
        if ((directory_pointer  = opendir(dir_name)) == NULL)
        {


                printf("Error opening dir \n ");
        }
        else
        {
                while ((entry = readdir(directory_pointer)) != NULL)
                {
                        if ( (strcmp(entry->d_name, "." ) == 0 ) || (strcmp(entry->d_name, ".." ) == 0))
                        {

                        }
                        else
                        {
                                printf("%s\n", entry->d_name);
                                strcat(file_cache, "\\");

                                strcat(file_cache, entry->d_name);
                                //   SeparateDicLongOrShort(file_cache);


                                //  SeparateDicToThree(file_cache,dir_name,dir_name,dir_name);
                                //  SeparateDicToThree(file_cache, dir_name, entry->d_name);
                                //  dir_out

                                DicTxtSort2( file_cache, dir_name, entry->d_name);

                                //   sprintf(  dir_outcache, "%s\\%s", dir_out, entry->d_name);
                                //   DicTxtSort3(file_cache, dir_outcache);
                        }
                        strcpy(file_cache, dir_name);
                }
                closedir(directory_pointer);
        }

}



void getFileExten( char cFileName[ MAX_PATH ] , char Exten[MAX_PATH / 10 ])
{
        //获得文件后缀名
        int len = 0, i, j, position = 0;

        len = strlen(cFileName);
        if (len < 1)
        {
                printf("\n 出错警告  文件名长度为0 \n");
                strcmp(Exten, "");
                return  ;
        }


        position = len;
        do
        {
                position--;
                if (position < 2)
                {
                        //无后缀名文件
                        strcmp(Exten, " ");
                        return  ;
                }
        }
        while (cFileName[position] != '.');
        j = 0;

        for (i = position + 1 ; i < len; i++)
        {
                Exten[j++] = cFileName[i];

        }

        if ((len - position) > (MAX_PATH / 10 - 1))
        {
                printf("\n 出错警告  文件名长度 可能过长\n");
                printf("%s \n", cFileName);
                Sleep(1000);
                return  ;
        }

        //   return Exten;
        return ;
}



int compare11(const void *a, const void *b)
{


        //   return strcmp((const char *)a, (const char *)b);

        return (strcmp(*(char**)a, *(char**)b));


        //char *s[100];//定义了一个指针数组，亦可称为指针的指针   return(strcmp(*(char**)a,*(char**)b));//注意这里使用char**表示指针的指针

        //    return(*(char *)a-*(char *)b);//这里直接把字符的ASCII码相减来比较字符的先后顺序

        //  char s[100][100];   return(strcmp((char*)a,(char*)b));/*这里调用了strcmp比较函数，这个函数根据字典序对字符串进行比较，按字符串的先后顺序依次返回1或0或-1*/
}

int DicTxtSort2 ( char  FileNameIn[MAX_PATH] , char  dir_name[MAX_PATH], char FileName [MAX_PATH]  )
{


        char Exten[MAX_PATH / 10 ] = { 0 };
        FILE *fp, *wreitFp;
        long int  wordCount = 0, KeyCount = 0;
        long   int i = 0, j = 0;

        int    wordLenCah = 0, wordMaxLen = 0 ;
        char TxtFileWrite[MAX_PATH] = { 0 };

        char Word[N] = { 0 };


        getFileExten(FileNameIn, Exten);

        if (( strcmp(Exten, "txt"  ) == 0) || (strcmp(Exten, "TXT"  ) == 0   ))
        {
                //    printf("后缀名 %s \n", Exten);
        }
        else
        {
                printf("%s 不是txt格式文件! \n", FileNameIn);
                return -2;
        }


        printf("\n 文件=%s\n", FileNameIn);

        // 打开文件
        if ((fp = fopen(FileNameIn, "r")) == NULL)
        {
                printf("%s open error !\n", FileNameIn);

                return -1;
                //return NULL;
        }


        char  FileSortPath[MAX_PATH] = { 0 };
        char  FileSort[MAX_PATH] = { 0 };
        sprintf(  FileSortPath, "%s\\Sort", dir_name);


        if (access(FileSortPath, 0)) //判断目录是否存在
        {
                printf("文件夹不存在！");

                if (_mkdir(FileSortPath) == 0)
                {
                        printf("创建成功！");
                }
                else
                {
                        printf("创建失败！");
                        return -4;

                }


        }
        else
        {

        }
        sprintf(  FileSort, "%s\\%s", FileSortPath, FileName);



        // 写入的文件名
        printf("\n 写入的文件名=%s\n", FileSort);

        if ((wreitFp = fopen(FileSort, "w+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileSort);
        }

        rewind(fp);
        rewind(wreitFp);

        i = 0;

        struct NODE *pHead ;//= (  struct NODE *)malloc(sizeof(  struct NODE));



        pHead = Create_Null_plist();

        // 尾节点
        struct NODE *pTail = pHead;
        pTail->pNext = NULL;

        int longCoeNum = 0;
        strcpy(pHead->WordList, "");

        printf("打开  %s 读取中  \n ", FileNameIn);

        while (!feof(fp))
        {
                fscanf(fp, "%s", Word);
                wordCount++;



                wordLenCah = strlen(Word);
                if (wordLenCah > wordMaxLen)
                {

                        //    if (longCoeNum % 10000== 0)
                        {
                                printf(" len %s  \n", Word);
                        }
                        wordMaxLen = wordLenCah;
                }

                if (wordLenCah > N - 2)
                {
                        longCoeNum++;
                        if (longCoeNum % 10000 == 0)
                        {
                                printf("字符串长度可能过长\n %s \n", Word);
                        }
                }
                else
                {
                        i++;
                        struct NODE  *pNew = (struct NODE *)malloc(sizeof(struct NODE));

                        strcpy(pNew->WordList   , Word);

                        pNew->num = i;

                        //   add_list(pHead , pNew);
                        add_list(pTail , pNew);

                        {

                                pTail = pTail->pNext;
                        }



                        if (i % 1000000 == 0)
                        {
                                printf(" len %s  \n", Word);
                        }


                        free(pNew);

                }


                //  printf(" len %s  \n", Word);

                strcpy(Word, "");
        }
        pTail->pNext = NULL;
        KeyCount =   i - 1;
        pHead->num = i;

        //      traverse_list(  pHead );

        printf(" 共 %ld 个密码 \n", KeyCount);
        printf(" 最长%d  \n", wordMaxLen);


        //   getchar();
        printf(" 读取中  正在 复制到数组中  \n " );



        //将链表中的密码保存到WordList数组中
        long  int m, n;
        m = ++ KeyCount;
        n = ++wordMaxLen ;

        int **WordList ;
        WordList = (char **)malloc(sizeof(char *) * m);    //分配指针数组
        long int k = 0;
        for (k = 0; k < m; k++)
        {
                //      WordList[k] = (char *)malloc(sizeof(char) * n);


        }

        struct NODE  *pNodes = pHead  ->pNext;

        for (  k = 0; k < m; k++)
        {
                WordList[k] = (char *)malloc(sizeof(char) * n);

                //    if ((k > 3035332)&&(k <30353328))
                {
                        //        printf(" %d = %p\n", k, WordList[k] ); // errno = 33


                }

                if (WordList[k] == NULL)
                {
                        perror("Error: ");
                        printf("errno = %d\n", errno); // errno = 33

                        printf("error: %s\n", strerror(errno)); // error: Numerical argument out of domain


                        printf("创建第 %ld 数组节点失败，终止 \n", k);

                        long  int i = 0;
                        for (i = k - 5; i < k; i++)
                        {
                                printf(" %ld = %p\n", i, WordList[i] ); // errno = 33

                        }
                        getchar();
                        exit(-1);
                }
                //  printf(" %ld.   %s \n" , pNodes->num, pNodes->WordList);

                strcpy( WordList[k] , pNodes->WordList);
                //  wsprintf( WordList[k], "%s", pNodes->WordList );
                //    strncpy( WordList[k], pNodes->WordList, n);

                pNodes = pNodes->pNext;

                //  printf(" %ld.   %s\n" , k, WordList[k]);
        }

        printf("  \n");
        printf("   复制 完成，准备排序 \n " );

        qsort(WordList, KeyCount, sizeof( WordList [0]),   compare11 );//可用
        //排序 密码单词

        printf("   排序 完成 \n " );


        //单词写入
        j = 1;
        for (  k = 0; k < m - 1; k++)
        {

                if (strcmp( WordList[k], WordList[k + 1]) == 0)
                {

                }
                else
                {
                        //  printf(" %ld.   %s\n" , k, WordList[k]);
                        fprintf(wreitFp, "%s\n" ,  WordList[k]);
                }


        }
        printf("   写入 完成 \n " );




        //释放动态开辟的空间

        for (i = 0; i < m; ++i)
        {

                free(WordList[i]);

        }

        free(WordList);
        WordList = NULL;
        printf(" 释放动态开辟的空间 完成 \n "  );
        if ( fclose(wreitFp))
        {
                printf("Error file close  %s  \n ", TxtFileWrite);
        }

        if ( fclose(fp))
        {
                printf("Error file close  %s  \n ", FileNameIn);
        }

        printf(" 释放链表\n "  );
        ListDestroy(  pHead);



        printf(" %s  排序 完成 \n " , FileNameIn);

        return 0;
}

int DicTxtSort3 ( char  FileNameIn[MAX_PATH] , char  FileNameOut[MAX_PATH] )
{

        //数组排序改成链表排序

        char Exten[MAX_PATH / 10 ] = { 0 };
        FILE *fp, *wreitFp;
        long int  wordCount = 0, KeyCount = 0;
        long   int i = 0, j = 0;

        int    wordLenCah = 0, wordMaxLen = 0 ;
        char TxtFileWrite[MAX_PATH] = { 0 };
        char  FileName[MAX_PATH] = { 0 };
        char Word[N] = { 0 };


        getFileExten(FileNameIn, Exten);

        if (( strcmp(Exten, "txt"  ) == 0) || (strcmp(Exten, "TXT"  ) == 0   ))
        {
                //    printf("后缀名 %s \n", Exten);
        }
        else
        {
                printf("%s 不是txt格式文件! \n", FileNameIn);
                return -2;
        }


        printf("\n 文件=%s\n", FileNameIn);

        // 打开文件
        if ((fp = fopen(FileNameIn, "r")) == NULL)
        {
                printf("%s open error !\n", FileNameIn);

                return -1;
                //return NULL;
        }


        i = 0;
        j = strlen( FileNameIn);

        do
        {
                FileName[i] = FileNameIn[i];
                i++;
        }
        while (i < j - 4);


        wsprintf( TxtFileWrite, "%s-sort.txt",  FileName )  ;

        //     wsprintf( TxtFileWrite, "%s",  FileNameOut )  ;


        // 写入的文件名
        printf("\n 写入的文件名=%s\n", TxtFileWrite);

        if ((wreitFp = fopen(TxtFileWrite, "w+") ) == NULL)
        {
                printf("Error file opening  %s \n ", TxtFileWrite);
        }

        rewind(fp);
        rewind(wreitFp);

        i = 0;

        struct NODE *pHead ;//= (  struct NODE *)malloc(sizeof(  struct NODE));



        pHead = Create_Null_plist();

        // 尾节点
        struct NODE *pTail = pHead;
        pTail->pNext = NULL;


        strcpy(pHead->WordList, "");

        printf("打开  %s 读取中  \n ", FileNameIn);

        while (!feof(fp))
        {
                fscanf(fp, "%s", Word);
                wordCount++;



                wordLenCah = strlen(Word);
                if (wordLenCah > wordMaxLen)
                {

                        wordMaxLen = wordLenCah;
                }

                if (wordLenCah > N - 2)
                {
                        printf("字符串长度可能过长\n %s \n", Word);
                }
                else
                {
                        i++;
                        struct NODE  *pNew = (struct NODE *)malloc(sizeof(struct NODE));

                        strcpy(pNew->WordList   , Word);

                        pNew->num = i;

                        //   add_list(pHead , pNew);
                        add_list(pTail , pNew);
                        //pTail->pNext = NULL;
                        //    while ( NULL != pTail->pNext)
                        {

                                pTail = pTail->pNext;
                        }
                        //    pTail->pNext = NULL;
                        /*
                                                pTail->pNext = pNew;
                                                pNew->pNext = NULL;
                                                pTail = pNew; //尾节点
                        */


                        if (i % 100000 == 0)
                        {
                                printf(" len %s  \n", Word);
                        }


                        free(pNew);
                        // i++;
                }


                //  printf(" len %s  \n", Word);

                strcpy(Word, "");
        }
        KeyCount =   i - 1;
        pHead->num = i;

        //      traverse_list(  pHead );

        printf(" 共 %ld 个密码 \n", KeyCount);
        printf(" 最长%d  \n", wordMaxLen);


        //   getchar();
        printf(" 读取中  正在 复制到数组中  \n " );



        //将链表中的密码保存到WordList数组中
        long  int m, n;
        m = ++ KeyCount;
        n = ++wordMaxLen ;


        /*

        int **WordList ;
        WordList = (char **)malloc(sizeof(char *) * m);    //分配指针数组
        long int k = 0;
        for (k = 0; k < m; k++)
        {
                //      WordList[k] = (char *)malloc(sizeof(char) * n);


        }

        struct NODE  *pNodes = pHead  ->pNext;

        for (  k = 0; k < m; k++)
        {
                WordList[k] = (char *)malloc(sizeof(char) * n);

                //    if ((k > 3035332)&&(k <30353328))
                {
                        //        printf(" %d = %p\n", k, WordList[k] ); // errno = 33


                }

                if (WordList[k] == NULL)
                {
                        perror("Error: ");
                        printf("errno = %d\n", errno); // errno = 33

                        printf("error: %s\n", strerror(errno)); // error: Numerical argument out of domain


                        printf("创建第 %ld 数组节点失败，终止 \n", k);

                        long  int i = 0;
                        for (i = k - 5; i < k; i++)
                        {
                                printf(" %ld = %p\n", i, WordList[i] ); // errno = 33

                        }

                        exit(-1);
                }
                //  printf(" %ld.   %s \n" , pNodes->num, pNodes->WordList);

                strcpy( WordList[k] , pNodes->WordList);
                //  wsprintf( WordList[k], "%s", pNodes->WordList );
                //    strncpy( WordList[k], pNodes->WordList, n);

                pNodes = pNodes->pNext;

                //  printf(" %ld.   %s\n" , k, WordList[k]);
        }

        printf("  \n");
        printf("   复制 完成，准备排序 \n " );
        qsort(WordList, KeyCount, sizeof( WordList [0]),   compare11 );//可用




        //单词写入
        j = 1;
        for (  k = 0; k < m - 1; k++)
        {

                if (strcmp( WordList[k], WordList[k + 1]) == 0)
                {

                }
                else
                {
                        //  printf(" %ld.   %s\n" , k, WordList[k]);
                        fprintf(wreitFp, "%s\n" ,  WordList[k]);
                }


        }
        printf("   写入 完成 \n " );


           qsort(WordList, KeyCount, sizeof( WordList [0]),   compare11 );//可用


           */
        struct NODE  *p  = (struct NODE *)malloc(sizeof(struct NODE));

        p  = quickSortList(pHead->pNext); //

        FileListWrite (    wreitFp ,   p);

        // traverse_list(p);


        //排序 密码单词

        printf("   排序 完成 \n " );

        /*
                   struct NODE *pList = (  struct NODE *)malloc(sizeof(  struct NODE));  // NULL  ;

                   //  struct NODE*q = (  struct NODE *)malloc(sizeof(  struct NODE));
                   pList  =  quickSortList(pHead->pNext);

                   FileListWrite (   filepath, "SortList" , pList);

           */



        if ( fclose(wreitFp))
        {
                printf("Error file close  %s  \n ", TxtFileWrite);
        }

        if ( fclose(fp))
        {
                printf("Error file close  %s  \n ", FileNameIn);
        }
        /*
                struct NODE *pList = (  struct NODE *)malloc(sizeof(  struct NODE));  // NULL  ;

                //  struct NODE*q = (  struct NODE *)malloc(sizeof(  struct NODE));
                pList  =  quickSortList(pHead->pNext);

                FileListWrite (   filepath, "SortList" , pList);

        */
        printf("    ListDestroy   \n "  );
        ListDestroy(  pHead);
        //ListDestroy(  p);
        printf("    ListDestroy 完成 \n "  );
        //traverse_list(p);

        printf(" %s  排序 完成 \n " , FileNameIn);

        return 0;
}


int DicCombine( char  FileNameA[MAX_PATH] , char  FileNameB[MAX_PATH]  , char  FileNameC[MAX_PATH]  )
{
        //将A B 内容合并到c里面

        FILE *fpA, *fpB, *writeFp;
        char tempA[MAX_PATH] = {0}, tempB[MAX_PATH] = {0}, tempC[MAX_PATH] = {0};

        printf(" DicCombine   \n" );

        if ((fpA = fopen(FileNameA, "r")) == NULL)
        {
                printf("%s open error !\n", FileNameA);
                // exit(-1);
                return -1;
        }

        if ((fpB = fopen(FileNameB, "r")) == NULL)
        {
                printf("%s open error !\n", FileNameB);
                // exit(-1);
                return -2;
        }


        if ((writeFp = fopen(FileNameC, "w+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileNameC);
                return -3;
        }
        printf(" DicCombine  open  \n" );

        fscanf(fpA, "%s", tempA);
        fscanf(fpB, "%s", tempB);

        printf("  file opening  %s    %s\n", tempA, tempB);

        /*   while ( (!feof(fpA)) && (!feof(fpB)))
           {
                   if ( strcmp(tempA, tempB) < 0)
                   {
                           strcpy(tempC, tempA);
                           fscanf(fpA, "%s", tempA);
                   }
                   else
                   {
                           if ( strcmp(tempA, tempB) > 0 )
                           {
                                   strcpy(tempC, tempB);
                                   fscanf(fpB, "%s", tempB);
                           }
                           else
                           {

                                   strcpy(tempC, tempB);
                                   fscanf(fpB, "%s", tempB);
                                   fscanf(fpA, "%s", tempA);
                           }
                   }
                   fprintf(writeFp, "%s\n", tempC);
           }

        */
        do
        {
                if ( strcmp(tempA, tempB) < 0)
                {
                        strcpy(tempC, tempA);
                        fscanf(fpA, "%s", tempA);
                }
                else
                {
                        if ( strcmp(tempA, tempB) > 0 )
                        {
                                strcpy(tempC, tempB);
                                fscanf(fpB, "%s", tempB);
                        }
                        else
                        {

                                strcpy(tempC, tempB);
                                fscanf(fpB, "%s", tempB);
                                fscanf(fpA, "%s", tempA);
                        }
                }
                fprintf(writeFp, "%s\n", tempC);
        }
        while ( (!feof(fpA)) && (!feof(fpB)));



        while (!feof(fpA))
        {

                strcpy(tempC, tempA);
                fscanf(fpA, "%s", tempA);
                fprintf(writeFp, "%s\n", tempC);

        }


        while (!feof(fpB))
        {

                strcpy(tempC, tempB);
                fscanf(fpB, "%s", tempB);
                fprintf(writeFp, "%s\n", tempC);

        }





        /*
                do
                {

                        strcpy(tempC, tempA);
                        fscanf(fpA, "%s", tempA);
                        fprintf(writeFp, "%s\n", tempC);

                }
                while (!feof(fpA));

                do
                {

                        strcpy(tempC, tempB);
                        fscanf(fpB, "%s", tempB);
                        fprintf(writeFp, "%s\n", tempC);

                }
                while (!feof(fpB));
        */






        if ( fclose(fpA))
        {
                printf("Error file close  %s  \n ", FileNameA);
                return -4;
        }
        if ( fclose(fpB))
        {
                printf("Error file close  %s  \n ", FileNameB);
                return -5;
        }
        if ( fclose(writeFp))
        {
                printf("Error file close  %s  \n ", FileNameC);
                return -6;
        }

}



int memu(  )
{

        char dir_name[MAX_PATH] = { 0 };
        char dir_out[MAX_PATH] = { 0 };

        strcpy(dir_name, "F:\\系统资源\\字典文件合集\\2");

        //   strcpy(dir_out, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\读取字典信息\\排序结果");

        strcpy(dir_out, "F:\\系统资源\\字典整理后");


        strcpy(dir_name, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\测试的字典\\Middle");
        strcpy(dir_out, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\排序结果");


        //   strcpy(dir_name, ".");

        //  strcpy(dir_out, "..");

        GetDirFileName (dir_name, dir_out );


        return 0;
}

int debug( )
{

        //       struct NODE *pNew = (struct NODE *)malloc(sizeof(struct NODE));
        //      WordList[k] = (char *)malloc(sizeof(char) * n);


        int  nodeSize = 0;
        int  arrlist = 0;
        long int m = 0, k, n;
        n = 20;

        nodeSize = (sizeof(struct NODE));
        arrlist = (sizeof(char) * n);

        printf("单个节点大小 %d \n", nodeSize);


        printf(" 单个数组大小 %d  \n",  arrlist );
        long int num = 0;
        num = 22142283 * 2 * 2;

        printf("链表大小 %ld MB \n", nodeSize * num / 1024 / 1024);

        //   num = 3034315;

        printf(" 数组大小 %ld  MB \n",  arrlist * num / 1024 / 1024);




        m = num;

        int **WordList ;
        WordList = (char **)malloc(sizeof(char *) * m);    //分配指针数组
        for (  k = 0; k < m; k++)
        {
                WordList[k] = (char *)malloc(sizeof(char) * n);

                //    if ((k > 3035332)&&(k <30353328))
                {
                        //        printf(" %d = %p\n", k, WordList[k] ); // errno = 33


                }

                if (WordList[k] == NULL)
                {
                        perror("Error: ");
                        printf("errno = %d\n", errno); // errno = 33

                        printf("error: %s\n", strerror(errno)); // error: Numerical argument out of domain


                        printf("创建第 %ld 数组节点失败，终止 \n", k);

                        long  int i = 0;
                        for (i = k - 5; i < k; i++)
                        {
                                printf(" %ld = %p\n", i, WordList[i] ); // errno = 33

                        }
                        getchar();
                        exit(-1);
                }
        }

        printf("创建完成，等待释放 \n", k);

        getchar();

        int i = 0;
        for (i = 0; i < m; ++i)
        {

                free(WordList[i]);

        }

        free(WordList);
        return 0;
}

int main(int argc, char *argv[])
{





        //
        char na[MAX_PATH] = { 0 };
        strcpy(na, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\测试的字典\\弱口令.txt");


        char dir_out[MAX_PATH] = { 0 }, dir_outcache[MAX_PATH] = { 0 };
        // strcpy(dir_out, "G:\\软件包\\跑wifi\\202.txt");
        strcpy(dir_out, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\排序结果\\弱口令0.txt");




        struct timing * timeSTR;
        timeSTR =  Timing_start();


        //   debug() ;
        //      memu(  );
        //DirFileName ( );
        char  FileNameA[MAX_PATH] ;
        char  FileNameB[MAX_PATH]  ;
        char  FileNameC[MAX_PATH] ;
        strcpy(FileNameA, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\测试的字典\\combine\\a2.txt");
        strcpy(FileNameB, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\测试的字典\\combine\\b2.txt");
        strcpy(FileNameC, "F:\\c代码\\c源程序\\blocks 测试\\算法练习\\txt字典排序整理\\测试的字典\\combine\\c2.txt");

        DicCombine(FileNameA, FileNameB, FileNameC);

        //   SeparateDicLongOrShort ( na );

        //    DicTxtSort3( na, dir_out);

        Timing_finish(timeSTR);
        Timing_show(timeSTR);
        Timing_destroy(timeSTR);



        system("PAUSE");
        return 0;
}



/*

int Bubble (  char * WordList[ ] , long int KeyCount)
{


        //冒泡排序
        char *t;
        long int  i, j;


        for (i = 1; i < KeyCount; i++)
        {
                for (j = 0; j < KeyCount - i; j++)
                {
                        if (strcmp(   WordList[j],  WordList[j + 1] ) > 0) //a[j]>a[j+1])
                        {
                                t = WordList[j];
                                WordList[j] = WordList[j + 1];
                                WordList[j + 1] = t;
                        }
                }
        }

        return 0;
}

*/
int compare1( const void *a, const void *b )
{
        //  return *(char*)a - *(char*)b;

        return (strcmp(*(char**)a, *(char**)b));


        //char *s[100];//定义了一个指针数组，亦可称为指针的指针   return(strcmp(*(char**)a,*(char**)b));//注意这里使用char**表示指针的指针

}

int DicTxtSort ( char  FileNameCach[N] )
{
        char TxtFileName[N] = { 0 };
        char  FileName[N] = { 0 };
        char Word[N] = { 0 };


        FILE *fp, *wreitFp;
        long int  wordCount = 0, KeyCount = 0;
        long   int i = 0, j = 0;
        int wordLen = 0,  wordLenCah ;
        //   char WordList[30000 ][N]={0};
        //  char *WordList, *WordListHead;
        // 方案1
        char **WordList, **WordListHead;

        WordList = (char**) malloc (sizeof(char *) * 1000000);
        //1M  13万条




        strcpy(TxtFileName, FileNameCach);
        printf("\n 文件=%s\n", TxtFileName);
        // 打开文件
        if ((fp = fopen(TxtFileName, "r")) == NULL)
        {
                printf("%s open error !\n", TxtFileName);
                // exit(-1);
                return -1;
                //return NULL;
        }


        i = 0;
        j = strlen( TxtFileName);

        do
        {
                FileName[i] = TxtFileName[i];
                i++;
        }
        while (i < j - 4);

        /*
        while ( TxtFileName[i] != '.')
        {
                FileName[i] = TxtFileName[i];
                i++;
        };
        */
        strcat(FileName, "qsort排序.txt");
        printf("  file opening  %s \n ", FileName);

        if ((wreitFp = fopen(FileName, "w+") ) == NULL)
        {
                printf("Error file opening  %s \n ", FileName);
        }

        rewind(fp);
        rewind(wreitFp);

        i = 0;
        while (!feof(fp))
        {
                fscanf(fp, "%s", Word);
                wordCount++;



                wordLenCah = strlen(Word);
                if (wordLenCah > N - 2)
                {
                        printf("字符串长度可能过长\n %s \n", Word);
                }
                else
                {

                        WordList[i] = (char*)malloc(sizeof(char) * (wordLenCah + 3));
                        //     WordList[i] = (char*)malloc(sizeof(char) * N);
                        strcpy(WordList[i] , Word);
                        i++;
                }





                strcpy(Word, "");
        }
        KeyCount = j = i;

        printf(" 共 %ld  i= %d \n", wordCount, i);

        printf(" 共 %ld 个密码 \n", wordCount);

        WordListHead = WordList;


        qsort(WordList, KeyCount, sizeof( WordList [0]),   compare1 );//可用


        //     Bubble (WordList, KeyCount); //可用



        for (i = 0; i < KeyCount; i++)
        {
                //第一个是空格
                fprintf(wreitFp, "%s\n", WordList[i] );

                //    if ( strcmp( WordList[i], WordList[i+1)]==0)
                {

                }

        }












        //释放动态开辟的空间

        for (i = 0; i < j; ++i)
        {

                free(WordList[i]);

        }

        free(WordList);
        WordList = NULL;
        /*
                printf(" 释放后 \n");
                printf("WordListHead sizef=  %d  \n", sizeof(*WordListHead ));
                printf("WordList sizef=  %d  \n", sizeof(*WordList ));
        */





        if ( fclose(wreitFp))
        {
                printf("Error file close  %s  \n ", FileName);
        }

        if ( fclose(fp))
        {
                printf("Error file close  %s  \n ", TxtFileName);
        }


        return 0;
}

