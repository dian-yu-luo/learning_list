package TextDome;


interface Animal{
    int BIG_TYPE = 5;
    void sleep();
    void eat();
    void breath();

}

 class Tiger implements Animal{
    public void breath() {
        System.out.println("The tiger breath");
    }
    //实现 eat 方法
    public void eat() {
        System.out.println("The tiger eat");
    }
    //实现 sleep 方法
    public void sleep() {
        System.out.println("The tiger sleep");
    }
    public static void main(String[ ] args) {
        Tiger tiger=new Tiger();
        tiger.breath();
        tiger.eat();
        tiger.sleep();
    }
}
