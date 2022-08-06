//求解树的深度
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    typedef struct TreeList
    {
        struct TreeNode *node;
        struct TreeList *next;
    } Trl;
    Trl first;
    first.node = root;
    first.next = NULL;
    Trl *List = &first, *nList, *tail, *tmp;
    int cnt = 0;
    while (List != NULL)
    {
        ++cnt;
        tmp = first.next; //暂存头结点以便释放
        first.next = NULL; //这一点很关键，因为一旦没有Trl添加到first(nList)后，那么first->next保留的将是上一次已经释放的节点，这个节点在本轮中还会free从而发生错误.而且在每一棵树中这种情况必然会出现.
        nList = &first; //&first就像锚一样固定在一个已知且不变的位置,每次便在first后面添加节点
        tail = nList; //避免tail=NULL的情况(头节点)
        while (List != NULL)
        {
            if (List->node->left != NULL)
            {
                tail = tail->next = (Trl *)malloc(sizeof(Trl));
                tail->node = List->node->left;
                tail->next = NULL;
            }
            if (List->node->right != NULL)
            {
                tail = tail->next = (Trl *)malloc(sizeof(Trl));
                tail->node = List->node->right;
                tail->next = NULL;
            }
            List = List->next;
        }
        List = tmp;
        while (List)
        {
            tmp = List->next;
            free(List);
            List = tmp;
        }
        List = nList->next; //n(ext)List=first(锚)->List(这里会将本已释放的节点赋给List)
    }
    return cnt;
}
//该方法将临时变量的地址作为链表的头结点,可以避免很多链表头结点特殊处理的步骤,但也有很多细节需要注意.
//值得好好回味这种结构.