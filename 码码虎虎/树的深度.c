//����������
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
        tmp = first.next; //�ݴ�ͷ����Ա��ͷ�
        first.next = NULL; //��һ��ܹؼ�����Ϊһ��û��Trl��ӵ�first(nList)����ôfirst->next�����Ľ�����һ���Ѿ��ͷŵĽڵ㣬����ڵ��ڱ����л���free�Ӷ���������.������ÿһ���������������Ȼ�����.
        nList = &first; //&first����êһ���̶���һ����֪�Ҳ����λ��,ÿ�α���first������ӽڵ�
        tail = nList; //����tail=NULL�����(ͷ�ڵ�)
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
        List = nList->next; //n(ext)List=first(ê)->List(����Ὣ�����ͷŵĽڵ㸳��List)
    }
    return cnt;
}
//�÷�������ʱ�����ĵ�ַ��Ϊ�����ͷ���,���Ա���ܶ�����ͷ������⴦��Ĳ���,��Ҳ�кܶ�ϸ����Ҫע��.
//ֵ�úúû�ζ���ֽṹ.