#include "iostream"
#include "vector"
#include "iterator"
using namespace std;

class vectorList
{
public:
    vectorList(int initialCapacity = 10);
    
    bool empty() {return element->size()==0;}
    size_t size() const {return element->size();}
    size_t capacity()const {return element->capacity();}
    int get(const int index) const;
    int indexOf(const int value) const;
    void erase(const int index);
    void insert(const int index,const int value);
    void push(const int value);
    bool checkIndex(const int index) const;
    void output()const;
    
    typedef vector<int>::iterator iterator;
    iterator begin() {return element->begin();}
    iterator end() {return element->end();};
    
private:
    vector<int> *element;
};

vectorList::vectorList(int initialCapacity)
{
    element = new vector<int>;
    element->reserve(initialCapacity);
}

bool vectorList::checkIndex(const int index) const
{
    if(index<0||index>=element->size())
    {
        printf("invalid index!");
        return false;
    }
    else
        return true;
}

int vectorList::get(const int index) const
{
    if(checkIndex(index)==false)
        return -1;
    else
    {
        return element->at(index);
    }
}

int vectorList::indexOf(const int value) const
{
    int index=0;
    for(auto i:*element)
    {
        if(i == value)
        {
            return index;
        }
        
        index++;
    }
    printf("no value:%d",value);
    return -1;
}

void vectorList::erase(const int index)
{
    
    if(checkIndex(index)==false)
        return;
    else
    {
        element->erase(element->begin()+index);
    }
}

void vectorList::insert(const int index, const int value)
{
    if(checkIndex(index)==false)
        return;
    else
    {
        element->insert(element->begin()+index, value);
    }
}

void vectorList::push(const int value)
{
    element->push_back(value);
}

void vectorList::output()const
{
    for(auto i:*element)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    vectorList list(20);
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.erase(1);
    list.insert(1, 2);

    list.output();
    
    auto a = list.begin();
    cout<<*a;
    
    return 0;
}

