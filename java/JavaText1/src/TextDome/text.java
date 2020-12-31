package TextDome;

import java.util.*;


class Time
{
    public int hour;
    public int minute;
    public int second;
}
public class text    {
    Time time;
    public static void main(String[ ] args) {
        text opt=new text();
        opt.time = new Time();
        opt.time.hour = 12;
        opt.time.minute = 45;
        opt.time.second = 20;
        System.out.println("time 的属性值：");
        System.out.println("hour="+opt.time.hour);
        System.out.println("minute="+opt.time.minute);
        System.out.println("second="+opt.time.second);
//将对象作为参数传递给方法 objectMethod
        opt.objectMethod(opt.time);
//对比执行方法后的变化
        System.out.println("执行方法之后的 time 的属性值：");
        System.out.println("hour="+opt.time.hour);
        System.out.println("minute"+opt.time.minute);
        System.out.println("second"+opt.time.second);
    }
    void objectMethod(Time t) {
        System.out.println("参数 t 的属性值：");
        System.out.println("hour="+t.hour);
        System.out.println("minute="+t.minute);
        System.out.println("second="+t.second);
        System.out.println("对 t 和 time 进行==比较，结果为："+(t==this.time));
        System.out.println("对 t 和 time 进行 equals 比较，结果为："+(t.equals(this.time)));
        System.out.println("改变 t 的实例变量值");
        t.hour=8;
        t.minute=12;
        t.second=24;
    }
}




