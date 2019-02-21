#include "iostream"
#include "cmath"
using namespace std;

struct chainNode
{
    int element;
    chainNode *next;
    
    chainNode()
    {
        this->element=-1;
        this->next=nullptr;
    }
    
    chainNode(const int &element)
    {
        this->next=nullptr;
        this->element = element;
    }
    
    chainNode(const int &element,chainNode *next)
    {
        this->element = element;
        this->next = next;
    }
};

class chain
{
public:
    chain(int initialCapacity=10);
    chain(const chain&);
    ~chain();
    
    chainNode operator[](const int i)
    {
        if(i>=listSize||i<0)
            return NULL;
        chainNode *targetNode = firstNode;
        for(int j=0;j<i;j++)
            targetNode = targetNode->next;
        
        return *targetNode;
    }
    
    bool operator==(chain list)
    {
        if(list.listSize==listSize)
        {
            chainNode *listNode1 = firstNode;
            chainNode *listNode2 = list.firstNode;
            while(listNode1!=nullptr&&listNode2!=nullptr)
            {
                if(listNode1->element==listNode2->element)
                {
                    listNode1 = listNode1->next;
                    listNode2 = listNode2->next;
                    
                }
                else
                    return false;
            }
            if(listNode2==nullptr)
                return true;
        }
        return false;
    }
    
    bool empty()const {return listSize==0;}
    int size()const{return listSize;}
    int capacity()const{return arrayLength;}
    int get(const int index)const;
    int indexOf(const int value)const;
    void setSize(const int theSize);
    void set(const int index,const int value);
    void removeRange(const int fromIndex,const int lastIndex);
    void insert(const int index,const int value);
    void erase(const int index);
    void push(const int value);
    void output()const;
    void reserve();
    
    void binSort(const int range);
    void baseSort(const int baseNum,const int max);
    
private:
    chainNode *firstNode;
    int listSize;
    int arrayLength;
    
};
void chain::reserve()
{
    chainNode *targetNode = firstNode;
    chainNode *nextNode = firstNode->next;
    chainNode *tempNode = nullptr;
    
    if(targetNode==nullptr || nextNode == nullptr)
        return;
    
    while(nextNode)
    {
        tempNode = nextNode->next;
        nextNode->next = targetNode;
        if(targetNode == firstNode)
            targetNode->next = nullptr;
        targetNode = nextNode;
        nextNode = tempNode;
    }
    firstNode = targetNode;
    
}

//基数排序法
void chain::baseSort(const int baseNum,const int max)
{
    chain *bin = new chain[baseNum+1];
    
    chainNode *targetNode = firstNode;
    int m = 0;
    
    for(int k=1;k<=max;k++)
    {
        while (targetNode != nullptr)
        {
            m = ((targetNode->element)%(int)pow(baseNum, k))/pow(baseNum, k-1);
            //            bin[m].insert(0, targetNode->element);
            bin[m].push(targetNode->element);
            targetNode = targetNode->next;
            this->erase(0);
        }
        
        for(int i=0;i<baseNum+1;i++)
        {
            while (bin[i].empty() == false)
            {
                this->push(bin[i].get(0));
                bin[i].erase(0);
            }
        }
        targetNode = firstNode;
    }
    
}

//箱子排序法
void chain::binSort(const int range)
{
    chain *bin = new chain[range + 1];
    
    chainNode *targetNode = firstNode;
    while(targetNode != nullptr)
    {
        bin[targetNode->element].insert(0, targetNode->element);
        targetNode = targetNode->next;
        this->erase(0);
    }
    
    for(int i=0;i<range+1;i++)
    {
        while (bin[i].empty() == false)
        {
            this->push(bin[i].get(0));
            bin[i].erase(0);
        }
    }
}

//析构函数
chain::~chain()
{
    while(firstNode!=nullptr)
    {
        chainNode *targetNode = firstNode->next;
        delete firstNode;
        firstNode = targetNode;
    }
}

//构造函数
chain::chain(int initialCapacity)
{
    listSize=0;
    arrayLength=initialCapacity;
    firstNode = nullptr;
}

chain::chain(const chain &p)
{
    listSize = p.listSize;
    if(listSize==0)
    {
        firstNode = nullptr;
        return;
    }
    
    chainNode *sourceNode = p.firstNode;
    firstNode = new chainNode(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode *targetNode = firstNode;
    while(sourceNode!=nullptr)
    {
        targetNode->next =new chainNode(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = nullptr;
}

//删除指定范围的元素
void chain::removeRange(const int fromIndex, const int lastIndex)
{
    if(fromIndex<0||fromIndex>listSize-1)
        return;
    if(lastIndex<fromIndex||lastIndex>listSize-1)
        return;
    
    chainNode *targetNode = firstNode;
    for(int i=0;i<fromIndex-1;i++)
        targetNode = targetNode->next;
    
    chainNode *fromNode = nullptr;
    if(fromIndex == 0)
        fromNode = targetNode;
    else
        fromNode = targetNode->next;
    
    chainNode *deleteNode = fromNode;
    for(int i=fromIndex;i<=lastIndex;i++)
    {
        fromNode = fromNode->next;
        delete deleteNode;
        deleteNode = fromNode;
    }
    if(fromIndex==0)
        firstNode = fromNode;
    else
        targetNode->next = fromNode;
    listSize = listSize - (lastIndex-fromIndex+1);
    return;
}

//改变指定位置的值
void chain::set(const int index, const int value)
{
    if(index<0||index>listSize-1)
        return;
    else
    {
        chainNode *targetNode = firstNode;
        for(int i=0;i<index;i++)
            targetNode = targetNode->next;
        targetNode->element = value;
        return;
    }
}

//改变链表大小
void chain::setSize(const int theSize)
{
    if(theSize>=listSize||theSize<0)
        return;
    else
    {
        if(theSize == 0)
        {
            chainNode *targetNode = firstNode;
            while (firstNode!=nullptr)
            {
                targetNode = targetNode->next;
                delete firstNode;
                firstNode = targetNode;
            }
            listSize=0;
            return ;
        }
        chainNode *lastNode = firstNode;
        for(int i=0;i<theSize-1;i++)
            lastNode = lastNode->next;
        chainNode *targetNode = lastNode->next;
        lastNode->next = nullptr;
        while(targetNode!=nullptr)
        {
            chainNode *deleteNode = targetNode;
            targetNode = targetNode->next;
            delete deleteNode;
        }
        listSize = theSize;
    }
}

int chain::get(const int index)const
{
    if(index<0||index>listSize-1)
        return -1;
    else
    {
        chainNode *targetNode;
        targetNode = firstNode;
        for(int i=0;i<index;i++)
            targetNode = targetNode->next;
        return targetNode->element;
    }
}

int chain::indexOf(const int value)const
{
    int theIndex=0;
    chainNode *targetNode = nullptr;
    targetNode = firstNode;
    while (targetNode!=nullptr)
    {
        if(targetNode->element==value)
        {
            return theIndex;
        }
        theIndex++;
        targetNode = targetNode->next;
    }
    printf("not find");
    return -1;
}

void chain::insert(const int index, const int value)
{
    if(index<0||index>listSize)
        return ;
    else
    {
        if(index == 0)
        {
            chainNode *addNode = new chainNode(value);
            addNode->next = firstNode;
            firstNode = addNode;
            listSize++;
            return ;
        }
        chainNode *targetNode = nullptr;
        targetNode = firstNode;
        for(int i=0;i<index-1;i++)
            targetNode = targetNode->next;
        chainNode *addNode = new chainNode(value,targetNode->next);
        targetNode->next = addNode;
        listSize++;
    }
}

void chain::erase(const int index)
{
    if(index<0||index>listSize-1)
        return ;
    else
    {
        if(index == 0)
        {
            chainNode *deleteNode = nullptr;
            deleteNode = firstNode;
            firstNode = firstNode->next;
            delete deleteNode;
            deleteNode = nullptr;
            listSize--;
            return;
        }
        chainNode *targerNode = nullptr;
        targerNode = firstNode;
        for(int i=0;i<index-1;i++)
            targerNode = targerNode->next;
        chainNode *deleteNode = targerNode->next;
        targerNode->next = deleteNode->next;
        delete deleteNode;
        deleteNode = nullptr;
        listSize--;
    }
}

void chain::push(const int value)
{
    if(firstNode==nullptr)
    {
        firstNode = new chainNode(value);
        listSize++;
        return;
    }
    else
    {
        chainNode *newNode = new chainNode(value);
        chainNode *targetNode = firstNode;
        while (targetNode->next!=nullptr)
            targetNode = targetNode->next;
        targetNode->next = newNode;
        listSize++;
        return;
    }
}

void chain::output()const
{
    chainNode *targetNode = firstNode;
    while(targetNode!=nullptr)
    {
        cout<<targetNode->element<<" ";
        targetNode = targetNode->next;
    }
    cout<<endl;
    
}



int main()
{
    chain list(3);
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    list.output();
    list.reserve();
    list.output();
}
