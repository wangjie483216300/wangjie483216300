package com.company.Study;
/**
 * 利用数组实现一个简单的栈
 * */
public class test1 {
    /**获取栈底元素*/
    public static String getDown(String[] strings){
        return strings[0];
    }
    /**获取栈顶元素*/
    public static String getTop(String[] strings){
        return strings[strings.length-1];
    }
    /**判断栈是否满*/
    public static boolean isEmpty(String[] strings){
        return (getTop(strings)!=null);
    }
    /**判断是否为空*/
    public static boolean isNull(String[] strings){
        return (getDown(strings)==null);
    }
    /**push进栈*/
    public static String Push(String[] strings,String s){
        String state = "";
        if (isEmpty(strings)){
            state = "栈满,不允许添加元素!";
        }else {
            for (int j = 0 ; j<strings.length ; j++ ){
                if (strings[j]==null){
                    strings[j] = s;
                    state = "添加成功,添加的元素为: "+s+" ,添加的位置为[ "+j+" ]";
                    break;
                }
            }
        }
        return state;
    }
    /**pop出栈*/
    public static String Pop(String[] strings){
        String state = "拿出的栈元素为: ";
        if (isNull(strings)){
            state = "此栈为空!";
        }else {
            for (int i= strings.length-1 ; i >=0 ; i--){
                if (strings[i] !=null){
                    state = state + strings[i]+"\t\t";
                    strings[i]=null;
                }
            }
        }
        return state;
    }
    public static int length(String[] strings){
        return strings.length;
    }
    public static void main(String[] args) {
        String[] strings = new String[10];
        System.out.println(isNull(strings));
        System.out.println(Push(strings,"123"));
        System.out.println(Push(strings,"456"));
        System.out.println(Push(strings,"789"));
        System.out.println(Push(strings,"wangjie"));
        System.out.println(length(strings));
        System.out.println(Pop(strings));
    }
}
