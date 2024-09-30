package catSubCat;

public class Cat {


    public String name = "Cat";
    public String toString(){return "Cat";}

    public static void printNames(Cat c1, Cat c2){
            System.out.println(c1.name + " " + c2.name);
    }
    
    public static void main(String[] args) {
            Cat c1 = new Cat();
            SubCat s1 = new SubCat();
            Cat.printNames(c1, s1);
            System.out.println(c1);
            System.out.println(s1);
            Cat c2 = s1;
            System.out.println(c2);
    }


}
