#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

//int占4个字节，最大为2147483647
#define MAX 2147483647

//代表赫夫曼树结点的结构体
struct HTNode
{
    int weight;
    int parent;
    int lchild, rchild;
    HTNode(int val = 0) : weight(val)
    {
        parent = 0;
        lchild = -1;
        rchild = -1;
    }
};

struct LetterFre
{
    char ch;   //存储字符
    int count; //出现的频率
};

//计算每个字符出现的频率
vector<LetterFre> CntFrequenceOfLetter(string str)
{
    vector<LetterFre> InfoList; //存储字符频率信息
    if (str.size() == 0)
        return InfoList;
    sort(str.begin(), str.end());
    char s = str[0];
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != s)
        {
            //将统计的信息存入结构体
            LetterFre letter;
            letter.ch = s;
            letter.count = count;
            InfoList.push_back(letter);
            //开始统计下一个字符
            s = str[i];
            count = 1;
        }
        else
        {
            count++;
        }
        //如果为最后一个字符
        if (i == str.size() - 1)
        {
            //将统计的信息存入结构体
            LetterFre letter;
            letter.ch = s;
            letter.count = count;
            InfoList.push_back(letter);
        }
    }
    return InfoList;
}
//从森林中选择权重最小的两棵树
void SelectTree(vector<HTNode> *T, int *s1, int *s2)
{
    int min = MAX;
    //选出第一小的
    for (int i = 0; i < T->size(); i++)
    {
        if ((*T)[i].parent == 0 && (*T)[i].weight <= min)
        {
            min = (*T)[i].weight;
            *s1 = i;
        }
    }
    min = MAX;
    //选出第二小的
    for (int i = 0; i < T->size(); i++)
    {
        if ((*T)[i].parent == 0 && (*T)[i].weight < min && *s1 != i)
        {
            min = (*T)[i].weight;
            *s2 = i;
        }
    }
}

//构造赫夫曼树
vector<HTNode> CrtHuffmanTree(vector<LetterFre> InfoList)
{
    vector<HTNode> HTNodeList(InfoList.size());
    if (HTNodeList.size() == 0)
        return HTNodeList;
    else
    {
        for (int i = 0; i < InfoList.size(); i++)
        {
            HTNodeList[i].weight = InfoList[i].count;
        }

        for (int j = InfoList.size(); j < 2 * InfoList.size() - 1; j++)
        {
            int s1 = 0, s2 = 0;
            //找到森林中权重最小的树
            SelectTree(&HTNodeList, &s1, &s2);
            //cout << s1 << " " << s2 << endl;
            //合并成新结点
            HTNode NewNode(HTNodeList[s1].weight + HTNodeList[s2].weight);
            NewNode.lchild = s1;
            NewNode.rchild = s2;
            HTNodeList[s1].parent = HTNodeList.size();
            HTNodeList[s2].parent = HTNodeList.size();
            HTNodeList.push_back(NewNode);
        }
    }
    return HTNodeList;
}

void CrtHuffmanCode(vector<LetterFre> list1, vector<HTNode> list2)
{
    vector<int> code;
    for (auto i = 0; i < list1.size(); i++)
    {
        cout << list1[i].ch << ": ";
        auto crr = i;
        while (list2[crr].parent != 0)
        {
            auto parent = list2[crr].parent;
            if (crr == list2[parent].lchild)
                code.push_back(0);
            else if (crr == list2[parent].rchild)
                code.push_back(1);
            crr = list2[crr].parent;
        }
        //反向遍历容器
        for (auto it = code.rbegin(); it != code.rend(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
        code.clear();
    }
}
int main()
{
    string s = "AAABBBBCCCCCCCCCCDDDDDDDDEEEEEEFFFFF";
    auto list = CntFrequenceOfLetter(s);
    auto TreeList = CrtHuffmanTree(list);
    CrtHuffmanCode(list, TreeList);
}
