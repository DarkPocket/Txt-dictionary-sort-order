//linkList.c
#include "linkList.h"
#include<malloc.h>
#include<string.h>


// 创建 链表
struct NODE *Create_plist()
{
        int len;
        int i = 0;
        int val = 0; //临时存放数据
        // 头节点
        struct NODE *pHead = (struct NODE *)malloc(sizeof(struct NODE));

        if (pHead == NULL)
        {
                printf("创建链表失败，终止 \n");


                exit(-1);
                return ;
        }
        // 尾节点
        struct NODE *pTail = pHead;
        pTail->pNext = NULL;



        printf("输入需要生成的链表节点个数 \n");
        scanf("%d", &len);

        for (i = 0; i < len; i++)
        {
                printf("输入第%d个节点值 \n", i);
                scanf("%d", &val);

                struct NODE *pNew = (struct NODE *)malloc(sizeof(struct NODE));
                if (pNew == NULL)
                {
                        printf("创建链表节点失败，终止 \n");
                        exit(-1);
                }

                //                pNew->data = val;
                pTail->pNext = pNew;
                pNew->pNext = NULL;
                pTail = pNew; //尾节点



        }
        return pHead;

}


struct NODE *Create_Null_plist()
{
        int len;
        int i = 0;
        int val = 0; //临时存放数据
        // 头节点
        struct NODE *pHead = (struct NODE *)malloc(sizeof(struct NODE));
        if (pHead == NULL)
        {
                printf("创建链表失败，终止 \n");
                exit(-1);
        }
        // 尾节点
        struct NODE *pTail = pHead;
        pTail->pNext = NULL;

        return pHead;

}

void traverse_list(struct NODE *pHead)
{
        struct NODE *p = pHead ;//->pNext;
        if ( p == NULL )
        {
                printf("链表 NULL \n");
                return ;
        }
        while ( NULL != p)
        {
                //  printf("地址   %p ", p);

                printf(" %d.   %s \n" , p->num, p->WordList);

                p = p->pNext;
        }
        printf("  \n");
        return ;

}

void showPiont(struct NODE *p )
{

        printf(" %d.   %s \n" , p->num, p->WordList);

        printf("\n");

}


// 链表是否为空
int is_empty(struct NODE *pHead)
{
        if ( pHead->pNext == NULL )
        {
                return 1;
        }
        else
        {
                return 0;
        }

}

int length_list(struct NODE *pHead)
{
        int len = 0;
        struct NODE *p = pHead->pNext;

        while ( NULL != p)
        {
                len++;
                p = p->pNext;
        }
        printf(" 链表len=%d \n", len);
        return len;

}

// 在第i个链表前面插入 新节点   值为x
int insert_list(struct NODE *pHead, int newstr, int x)
{
        int i = 0;
        struct NODE *p = pHead;
        struct NODE *q;
        while (NULL != p && i < newstr - 1)
        {
                p = p->pNext;
                i++;

        }
        if (i > newstr - 1 || NULL == p)
        {
                return -1;
        }


        struct NODE  *pNew = (struct NODE *)malloc(sizeof(struct NODE));
        if (NULL == pNew)
        {
                printf("创建链表节点失败，终止 \n");
                return -2;
                //   exit(-1);
        }
        pNew->num = x;

        q = p->pNext;
        p->pNext = pNew;
        pNew->pNext = q;

        return 1;

}


//删除j节点后面的节点
int delete_list(struct NODE *pHead, int j, int *x)
{
        int i = 0;
        struct NODE *p = pHead, *s;
        struct NODE *q;
        while (NULL != p->pNext && i < j - 1)
        {
                p = p->pNext;
                i++;

        }
        if (i > j - 1 || NULL == p->pNext)
        {
                return -1;
        }

        //     pNew->data = x;
        q = p->pNext;
        *x = q->num;
        //删除p节点后面的节点

        s = p->pNext;
        p->pNext = s->pNext;
        free(q);
        q = NULL;

        return 1;

}

int CopyListNode (  struct  NODE * qHead, struct  NODE * Copy_pHead )
{
        //by black


        *qHead = *Copy_pHead;



        Copy_pHead = Copy_pHead->pNext;

        struct NODE   *pTail = qHead;

        printf("复制链表中\n" );

        while ( NULL != Copy_pHead)
        {

                struct  NODE *pNew = (struct  NODE *)malloc(sizeof(struct  NODE));

                *pNew = *Copy_pHead;



                //    printf("复制 val  %4d  data %2d \n", pNew->val , pNew->data);
                //    getchar();
                pTail->pNext = pNew;
                pTail = pNew;
                Copy_pHead = Copy_pHead->pNext;


        }
        pTail->pNext = NULL;



        return 0;
}







void Bublle_sort_list(struct NODE *pHead )
{
        int i, j, t;
        struct NODE *p, *q;
        int len;
        len = length_list(pHead);
        i = j = t = 0;


        for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
        {
                for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
                {
                        if (p->num > q->num)
                        {
                                t = p->num;
                                p->num = q->num;
                                q->num = t;
                        }


                }
        }

        return ;

}

int add_list(struct NODE *pHead, struct NODE *qList)  //添加节点
{

        int i = 0;
        struct NODE *p = pHead;

        while ( NULL != p->pNext)
        {

                p = p->pNext;
        }

        struct NODE *pNew = (struct NODE *)malloc(sizeof(struct NODE));
        if (pNew == NULL)
        {
                printf("创建链表节点失败，终止 \n");
                exit(-1);
        }


        *pNew = *qList;

        p->pNext = pNew;

        pNew->pNext = NULL;



        return 0;
}




//销毁链表

void ListDestroy(struct NODE*head)
{
        struct NODE *p, *q;
        //
        p = head;
        if (  NULL == head->pNext)
        {
                //     free(head);
                //    head = NULL;

                printf("  链表 NULL \n" );
                return  ;
        }

        while (p->pNext != NULL)
        {
                q = p->pNext;
                p->pNext = q->pNext;
                free(q);
        }


              printf("errno = %d\n", errno); // errno = 33

                        printf("error: %s\n", strerror(errno)); // error: Numerical argument out of domain


        free(p);
      //  free(head);
        p = NULL;

       // head = NULL;


        //head = NULL;
        return ;
}

struct NODE* partitionList( struct NODE* lowPre,  struct NODE* low,  struct NODE* high)
{
        //链表范围是[low, high)
        int key = low->num; //排序标准


        //        strcpy(key,low.WordList);

        struct NODE node1, node2;//比key小的链的头结点，比key大的链的头结点
        struct NODE* little = &node1, *big = &node2;
        struct NODE*i;
        for (  i = low->pNext; i != high; i = i->pNext)
                //    if (i->num < key)
        {
                //   strcpy(cache, i.WordList );
                if (strcmp( i->WordList,  low->WordList) < 0)
                        //  if (strcmp(cache, keys) < 0)
                {
                        little->pNext = i;
                        little = i;
                }
                else
                {
                        big->pNext = i;
                        big = i;
                }
        }
        big->pNext = high;//保证子链表[low,high)和后面的部分连接
        little->pNext = low;
        low->pNext = node2.pNext;
        lowPre->pNext = node1.pNext;//为了保证子链表[low,high)和前面的部分连接
        return low;
}

void qsortList( struct NODE *headPre,  struct NODE*head,  struct NODE*tail)
{
        //链表范围是[low, high)
        if (head != tail && head->pNext != tail)
        {
                struct NODE* mid = partitionList(headPre, head, tail);//注意这里head可能不再指向链表头了
                qsortList(headPre, headPre->pNext, mid);
                qsortList(mid, mid->pNext, tail);
        }
}

struct NODE *quickSortList( struct NODE *head)
{
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //链表快速排序
        if (head == NULL || head->pNext == NULL)
        {
                return head;
        }
        struct NODE tmpHead;
        tmpHead.pNext = head;
        qsortList(&tmpHead, head, NULL);
        //    return &tmpHead;
        return tmpHead.pNext;
}


int FileListWrite1 (  char  filepath[MAX_PATH], char  fileAddpath[MAX_PATH] , struct NODE *pHead)
{


        struct NODE *p = pHead ;//->pNext;
        if ( p == NULL )
        {
                printf("链表 NULL \n");
                return ;
        }
        while ( NULL != p)
        {
                //  printf("地址   %p ", p);

                fprintf(" %d.   %s \n" , p->num, p->WordList);

                p = p->pNext;
        }
        printf("  \n");
        return ;

}



int FileListWrite (   FILE  *wreitFp , struct NODE *pHead)
{
        char wordCache[N] = {0};

        struct NODE *p = pHead ;//->pNext;
        if ( p == NULL )
        {
                printf("链表 NULL \n");
                return ;
        }

        strcpy(wordCache, "");

        while ( NULL != p)
        {
                //  printf("地址   %p ", p);
                /*
                    if (strcmp( WordList[k], WordList[k + 1]) == 0)
                              {

                              }
                              else
                              {
                                      //  printf(" %ld.   %s\n" , k, WordList[k]);
                                      fprintf(wreitFp, "%s\n" ,  WordList[k]);
                              }
                */
                if (strcmp( p->WordList, wordCache) == 0)
                {
                        p = p->pNext;
                }
                else
                {
                        fprintf(wreitFp, "%s\n"  , p->WordList);

                        strcpy(wordCache, p->WordList);

                }
                //    fprintf(wreitFp, "%s\n"  , p->WordList);


        }
     //    fprintf(wreitFp, "%s\n"  , p->WordList);

        // printf("  \n");
        return ;

}




