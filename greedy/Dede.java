class Deamont extends Thread{
    @Override
    public void run(){
        System.out.println(getName());
    }
}
class Deamone extends Thread{
    @Override
    public void run(){
        System.out.println(getName());
    }
}




public class Dede{
    public static void main(String[] args) {
        Deamont t1 = new Deamont();
        t1.setName("Deamont");
        Deamone t2 = new Deamone();
        t2.setName("Deamone");
        t1.start();
        t2.start();
    }
}