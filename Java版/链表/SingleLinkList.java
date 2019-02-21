package LinkListPack;

public class SingleLinkList {
    /*
     *  实现单链表、循环链表、双向链表，支持增删操作
     *  实现单链表反转
     *  实现求链表的中间结点
     */

    class node
    {
        node(int value)
        {
            this.value = value;
            this.next = null;
        }

        private int value;
        private node next;
    }

    private node head;

    private node last;

    private int length;

    SingleLinkList()
    {
        head = new node(0);
        last = head;
        length = 0;
    }

    //增加结点
    void add(int value)
    {
        node crrNode = new node(value);
        last.next = crrNode;
        last = crrNode;
        length = length + 1;
    }

    void remove(int index)
    {
        if (index >= length)
        {
            return;
        }

        node crrNode = head;
        while(index > 0)
        {
            crrNode = crrNode.next;
            --index;
        }

        crrNode.next = crrNode.next.next;
        --length;
    }

    void insert(int index,int value)
    {
        if (index > length)
        {
            return;
        }

        node crrNode = head;
        while(index > 0)
        {
            crrNode = crrNode.next;
            --index;
        }

        node newNode = new node(value);
        newNode.next = crrNode.next;
        crrNode.next = newNode;
        ++length;
    }

    //反转链表
    void reverse()
    {
        if (length <= 1)
            return;
        node preNode = head.next;
        node crrNode = preNode.next;
        preNode.next = null;

        while(crrNode != null)
        {
            node nextNode = crrNode.next;
            crrNode.next = preNode;
            preNode = crrNode;
            crrNode = nextNode;
        }
        head.next = preNode;
    }

    int getMidNodeValue()
    {
        //1：使用length直接计算

        //2：使用双指针方案
        node ptr1 = head;
        node ptr2 = head;

        while(ptr2 != null && ptr2.next != null)
        {
            ptr1 = ptr1.next;
            ptr2 = ptr2.next.next;
        }
        return ptr1.value;
    }

    //打印
    void printOut()
    {
        node crrNode = head.next;
        while (crrNode != null)
        {
            System.out.print(crrNode.value + " ");
            crrNode = crrNode.next;
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        SingleLinkList list = new SingleLinkList();
        list.add(1);
        list.add(2);
        list.add(3);
        list.printOut();
        list.remove(1);
        list.insert(1,4);
        list.printOut();
        System.out.println(list.getMidNodeValue());
        list.reverse();
        list.printOut();
    }




}
