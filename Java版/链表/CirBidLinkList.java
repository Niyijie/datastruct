package LinkListPack;

public class CirBidLinkList {
    /*
    *   循环双向链表
    */

    class node
    {
        node(int value)
        {
            this.value = value;
            pre = null;
            next = null;
        }

        node pre;
        node next;
        int value;
    }

    private node head;
    private int length;

    node last;


    CirBidLinkList()
    {
        head = new node(0);
        last = head;
        length = 0;
    }

    void add(int value)
    {
        node newNode = new node(value);

        last.next = newNode;
        newNode.pre = last;

        last = newNode;
        ++length;
        //形成循环
        head.next.pre = last;
        last.next = head.next;

    }

    void insert(int index,int value) {
        if (index > length)
            return;
        //如果干好插入到尾部
        if (index == length) {
            add(value);
            return;
        }

        node newNode = new node(value);
        node crrNode = head;
        while (index >= 0) {
            crrNode = crrNode.next;
            --index;
        }

        node preNode = crrNode.pre;
        preNode.next = newNode;
        newNode.next = crrNode;
        crrNode.pre = newNode;
        newNode.pre = preNode;

        if (crrNode == head.next)
        {
            head.next = newNode;
        }

        ++length;
    }

    void remove(int index)
    {
        if (index > length)
            return;

        node crrNode = head.next;
        while (index > 0) {
            crrNode = crrNode.next;
            --index;
        }

        node preNode = crrNode.pre;
        node nextNode = crrNode.next;

        preNode.next = nextNode;
        nextNode.pre = preNode;

        if (crrNode == head.next)
        {
            head.next = nextNode;
        }
        //取消引用
        crrNode.next = null;
        crrNode.pre = null;
    }


    void printOut()
    {
        node crrNode = head.next;
        do {
            System.out.print(crrNode.value + " ");
            crrNode = crrNode.next;
        }while(crrNode != head.next);

        System.out.println();
    }

    void printOutRe()
    {
        node crrNode = head.next.pre;
        do
        {
            System.out.print(crrNode.value + " ");
            crrNode = crrNode.pre;
        }while (crrNode != head.next.pre);
        System.out.println();
    }


    public static void main(String[] args)
    {
        CirBidLinkList list = new CirBidLinkList();
        list.add(1);
        list.add(2);
        list.add(3);
        list.printOut();
        list.printOutRe();

        list.insert(3,4);
        list.printOut();
        list.printOutRe();

        list.remove(1);
        list.printOut();

    }


}
