public class ArrayList {

    /*
     *  实现一个支持动态扩容的数组,支持动态增删改操作
     *  实现两个有序数组合并为一个有序数组
     */

    private int[] array;

    private int capacity;   //总容量

    private int length;     //当前存储的数量

    private int scale = 2;

    ArrayList(int capacity)
    {
        this.capacity = capacity;
        this.length = 0;
        array = new int[capacity];
    }

    //默认构造函数
    ArrayList()
    {
        this.capacity = 10;
        this.length = 0;
        array = new int[this.capacity];
    }

    int getCapacity()
    {
        return capacity;
    }

    int getLength()
    {
        return length;
    }

    private void changeArraySize() {

        //扩容
        capacity = (int) (capacity * scale);
        int[] array_new = new int[capacity];
        //拷贝
        for (int i = 0; i < length; i++) {
            array_new[i] = array[i];
        }
        array = array_new;
    }


    int get(int index)
    {
        if (index > length-1)
        {
            return -1;
        }

        return array[index];
    }

    void add(int value)
    {
        if(capacity == length) {
            changeArraySize();
        }

        array[length] = value;
        length = length + 1;
    }

    void insert(int index,int value)
    {
        if (index > length)
            return;

        if(capacity == length) {
            changeArraySize();
        }

        //往后移一格
        for (int i=length-1;i>=index;--i)
        {
            array[i+1] = array[i];
        }

        array[index] = value;
        length = length + 1;
    }

    int remove(int index)
    {
        if (index >= length)
        {
            return -1;
        }

        int ret = array[index];

        //往前移一格
        for (int i=index+1;i<length;i++)
        {
            array[i-1] = array[i];
        }

        length = length - 1;
        return ret;
    }

    void printOut()
    {
        for (int i=0;i<length ;++i) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    //假设都为有序数组
    static ArrayList merge(ArrayList list1,ArrayList list2) {
        ArrayList newList = new ArrayList(list1.getLength() + list2.getLength());
        int index1 = 0;
        int index2 = 0;
        while (index1 < list1.getLength() && index2 <list2.getLength()) {

            if (list1.get(index1) < list2.get(index2))
            {
                newList.add(list1.get(index1));
                ++index1;
            }
            else
            {
                newList.add(list2.get(index2));
                ++index2;
            }
        }

        if (index1 == list1.getLength())
        {
            while(index2 < list2.getLength())
            {
                newList.add(list2.get(index2));
                ++index2;
            }
        }
        else
        {
            while(index1 < list1.getLength())
            {
                newList.add(list1.get(index1));
                ++index1;
            }
        }
        return newList;
    }


    public static void main(String[] agrv)
    {
        System.out.println("hello");

        ArrayList list = new ArrayList(2);
        list.add(1);
        list.add(2);
        list.printOut();
        list.add(3);
        list.remove(0);
        list.remove(0);

        list.printOut();
        list.insert(1,5);
        list.printOut();

        ArrayList list1 = new ArrayList(3);
        ArrayList list2 = new ArrayList(3);

        list1.add(1);
        list1.add(3);
        list1.add(5);

        list2.add(2);
        list2.add(4);
        list2.add(6);

        ArrayList newList = ArrayList.merge(list1,list2);
        newList.printOut();

    }
}
