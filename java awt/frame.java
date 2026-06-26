import java.awt.*;
//package swap;
    
class Swap extends Frame{
      Label l1,l2;
    TextField t1,t2;
    Button b;

    Swap(){
           super("my frame");
        setLayout (new FlowLayout());
        l1=new Label("first number");
        l2=new Label("second number");

        t1=new TextField(10);
        t2=new TextField(10);

        b=new Button("ok");
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(b);

    }
     
    public static void main(String args[]){
       
       Swap f=new Swap();
        f.setSize(400,400);
        f.setVisible(true);




    }
}