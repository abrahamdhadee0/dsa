class newthread extends Thread{
    public void run(){
        System.out.println("This is a new thread");
        System.out.println("Thread name: " + Thread.currentThread().getName());
    }
    public void run(int a){
        System.out.println("This is a new thread");
        System.out.println("Thread name: " + Thread.currentThread().getName());
    }
}


public class javapractice {
    public static void main(String[] args) {
        newthread t1 = new newthread();
        t1.start();
        t1.start();
    }
}