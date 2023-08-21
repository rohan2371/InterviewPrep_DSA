package bit_manipulation;

public class BitwiseHacks {

    static int set(int number,int pos){
            number |= 1 << pos;
            return number;
    }

    /*
    * 2. how to unset a bit in nth position
    * let suppose num = 7   (binary format is 0111)
    * so i want to unset the position 2
    * num = 0 1 1 1
    * pos = 3 2 1 0
    *
    * subsequently it will become -> 0 0 1 1  unsetting the 2nd position
    *
    * algorithm :
    *       1. first use left shift operator to move set bit to nth position
    *            res = 1 << pos  -> 0001 << 2 = 0100
    *       2. then i apply negation so that except that position every bit become 1
    *           res = ~res; -> 1011
    *
    *       3. afterwards just perform bitwise and operator
    *           num = num & res
    *
    *               0 1 1 1  -> binary format of num = 7
    *            &  1 0 1 1  -> binary format of res
    *               -------
    *               0 0 1 1 -> binary format of 3
    * */

    static int unSet(int num ,int pos)
    {
//        int res = 1 << pos;
//        res=~res;
//        num = res & num;
        // alternate one line code
        num &= ~(1<<pos);
        return num;
    }


    /*
    3.  Toggling a bit at nth position :
        Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1)
        previously. We will be using the ‘XOR’ operator here which is this ‘^’.
        The reason behind the ‘XOR’ operator is because of its properties.

        Properties of ‘XOR’ operator.
         1^1 = 0
         0^0 = 0
         1^0 = 1
         0^1 = 1
        If two bits are different then the ‘XOR’ operator returns a set bit(1) else
        it returns an unset bit(0).
     */

    static int toggLingBit(int num,int pos)
    {
        num^= 1<<pos;
        return num;
    }


    /*
    4. Checking if bit at nth position is set or unset:
        It is quite easily doable using the ‘AND’ operator.

        Left shift ‘1’ to given position and then ‘AND'(‘&’).

         num = 6 -> 0110
         so i just want to check position 3 weather is
         num  = 0 1 1 0
         pos =  3 2 1 0

         so we can see position bit is 0 ans will be 0
     */

    public static int atPosition(int num, int pos)
    {
        int bit = num & (1 << pos);
        return bit;
    }


    public static void main(String[] args) {
        /*
        * 1. How to set a bit in the number 'num' :-
        * // first i want to explain what is  mean by set a bit
        *   let suppose num = 4 -> binary format is 100
        * position count order will be right to left  basically what i mean is that
        *  num = 1 0 0
        * pos =  2 1 0
        *
        *  so i want to set position 1 that means position 1 will be convert into  0 -> 1
        * therefore ,  after performing our num look like this -> 110
        * Note: If the bit would be already set then it would remain unchanged.
        *
        * algorithm :
        *   1. first we left shift '1' to n position (1 << n) here n is position
        *   2. then , use the or operator to set the bit at that position. 'OR' operator is used because it will
        *     set the bit even if bit is unset previously in binary format of num
        *
        *   num = 4 -> 1 0 0 in binary format , pos 1
        *          pos 2 1 0
        *
        *  so after result it will be converted to 110
        *
        * binary format of 1       -> 001
        * 1.  res = 1 << pos         -> 1 << 1  = 010
        *
        * 2. num = num | res;
        *        num ->   100
        *        res -> | 010
        *                 ---
        *                 110    -> 6
        *
        * */


        int num = 4,pos = 1;
        int res =  1 << pos;
        System.out.println("res : "+res);
        num =  num | res;
        System.out.println("num : "+num);


        /*
        * num = 6 -> binary format 0110
        * pos = 0th ( 0110 -> 0111)  decimal format is 7
        *
        * res = 1 << pos    -> 1<<0  result will be same 0001
        *
        *   0001 << 0   -> 0001
        *
        * num = num | res ;
        *       num = 0110
        *       res = 0001  |
        *             ----
        *             0111 -> decimal format is 7
        *
        * here i am creating method set and passing num by reference
        *
        * */

        int number = 6;
        number = set(number,0);
        System.out.println("number : "+number);

        int a = 7;
        a = unSet(a,2);
        System.out.println("unsetting the a position 2 : " +a);


        int toggle  = 7;
        toggle = toggLingBit(toggle,2);
        System.out.println("toggle : "+toggle);

        int ans = atPosition(6,3);
        System.out.println("ans : "+ans);


        int ab = 5;// 110
        // position 2 ko unset karna hai result will look like -> 010



    }

}
