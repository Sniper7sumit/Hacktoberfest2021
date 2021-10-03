class Solution {
    public String intToRoman(int num) {
        
       int[] numarr = { 1000,900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        
 String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
     
        
        
        StringBuilder sb = new StringBuilder();
                       
                       for( int i=0; i<numarr.length; i++){
                           
                           while( num >= numarr[i]){
                               sb.append(romans[i]);
                               num -= numarr[i];
                               
                           }
                       }
                       
                       return sb.toString();
                      
    }
}
