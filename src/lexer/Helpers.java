package lexer;

public class Helpers {
    public static <T> boolean containsInArray(T[] arr, T ele){
        for (T element : arr){
            if (element.equals(ele)){
                return true;
            }
        }
        return false;
    }
}
