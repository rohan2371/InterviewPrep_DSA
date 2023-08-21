package bit_manipulation;

public class EvenOddUsingBitwiseOp {

    /*
    * 1 to 12 binary representation
    *
    * 1 ->  0001
    * 2 ->  0010
    * 3 ->  0011
    * 4 ->  0100
    * 5 ->  0101
    * 6 ->  0110
    * 7 ->  0111
    * 8 ->  1000
    * 9 ->  1001
    * 10 -> 1010
    * 11 -> 1011
    * 12 -> 1100
    * */

    public static void main(String[] args) {
        /*
         * 1. Check number is even or odd number using And Operator
         *
         * num = 5 -> 0101
         *
         *           0101     -> 5 in binary format
         *         & 0001     -> 1 in binary format
         *           ----
         *           0001     -> 1 in binary format
         *
         *
         * num = 6 -> 0110
         *
         *         0110       -> 6 in binary format
         *      &  0001       -> 1 in binary format
         *         ----
         *         0000       ->0 in binary format
         *
         * conclusion : As it can observed AND operation of a number with 1 will be 1 , if it odd
         * otherwise 0 if number is even
         *
         *
         *
         *
         *
         *
         * */
        int num = 5;
        if((num&1) == 0){
            System.out.println(num+" given number is even number");
        }else{
            System.out.println(num+" given number is odd number");
        }


        /*
        * EX-OR (X-OR)  truth table
        *
        *   A  ⊕  B   =   Y
        *   0     0   =   0
        *   0     1   =   1
        *   1     0   =   1
        *   1     1   =   0
        *
        *  trick : if even number of input is one then op is 0 and odd number of input is 1 then op : 1
        * ex : 0 0 1 = 1 , 0 1 1 = 0 , 1 1 1 = 1, 0 1 0 = 1, 1 1 0 = 0 ,
        *
        *       num = 6 ->110
         *
         *          110     -> 6 in binary format
         *        ^ 001     -> 1 in binary format
         *          ---
         *          111     -> 7 in binary format
         *
        *
        * num = 5 -> 101
        *
        *          101    -> 5 in binary format
        *        ^ 001    -> 1 in binary format
        *          ---
        *          100 -> it is binary format of  4
        *
        *

        * Conclusion :  As it can observed XOR of a number with 1 , increments it by 1 if is even ,
        *               otherwise decrements it by 1 if it odd number
        * */
        int num1 = 6;
        int b= num1^1;

        if(b==num1+1){
            System.out.println(num1+" Given number is even number");
        }else{
            System.out.println(num1+" Given number is odd number");
        }


        /*
        * Check Number is Even or Odd using OR Operator->
        *
        *
        *  num = 12 -> 1100
         *
         *       1100   -> 12 in binary format
         *     | 0001   -> 1 in binary format
         *       ----
         *       1101   -> 13 in binary format
         *
         *
        * num  = 11 -> 1011
        *
        *        1011   -> 11 in binary format
        *      | 0001   -> 1 in binary format
        *        ----
        *        1011 -> 11 in binary format
        *
        *
        *
        *
        *
        *   conclusion : if num is even is increments by 1 otherwise it will be same
        *
        *
        * */

        int num3 = 11;
        int check = num3 | 1;
        if(check == num3+1){
            System.out.println(num3+" it is even number");
        }else{
            System.out.println(num3+" it is odd number");
        }


        /*
        * 4. Check number is even or odd using bitwise shift operator
        *
        *
        *         num = 11 -> 1011
        *
        * num = num >>  1   ->0101   -> 1 is pop out from left -> it is right shift operator
        *
        * num = 0101
        * num = num <<  1   ->1010   -> 0 is push from left    -> it is left shift operator
        *
        *
        * num = 12  -> 1100
        * num = num >> 1     -> 0110 -> right shift by 1
        * num = 0110
        *
        * num = num << 1 -> 1100 -> left shift by 1
        *
        * conclusion :  after doing right shift ,left shift operation if number remain same then num is even
        *               number otherwise odd number
        *
        * */

        int num4  = 12 ; // binary format is 1100

        int temp = num4 >> 1;
        temp = temp << 1;
        if(temp == num4){
            System.out.println(num4+" is even number ");
        }else{
            System.out.println(num4+" is odd number");
        }
        // let suppose i want to check in one line

        int num5 = 12;

        if(num5 == (num5>>1) << 1){
            System.out.println(num5+" is even num");
        }else{
            System.out.println(num5+" is odd num");
        }
    }
}
