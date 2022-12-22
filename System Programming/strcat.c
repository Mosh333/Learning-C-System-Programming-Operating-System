#include <stdio.h>
#include <string.h>

char * my_strcat(const char *, const char *);
int string_length(const char * const str);
void print_string_char_by_char(const char *);
void testcase1_twoNormalStrings(const char *, const char *);
void testcase2_oneNormalStringOneNullChar(const char *, const char *);
void testcase3_oneNullCharOneNormalString(const char *, const char *);
void testcase4_twoNullChars(const char *, const char *);
void testcase5_twoStringsWithSpecialChars(const char *, const char *);

int main() {
   // printf() displays the string inside quotation
   printf("Running program now\n");

   //printf("%s\n", my_strcat("Hello", "world!"));
   testcase1_twoNormalStrings("Hello", "world!" );
   testcase2_oneNormalStringOneNullChar("Hello", '\0' );
   testcase3_oneNullCharOneNormalString('\0', "Hello" );
   testcase4_twoNullChars("\0", '\0');
   testcase5_twoStringsWithSpecialChars("学年別漢字配当表", "وحة المفاتيح");

   printf("Ending program now\n");
   return 0;
}


char * my_strcat(const char * const str1, const char * const str2){
        int i;
        char *p;
        if(str1 == '\0' && str2 == '\0'){
                return str1;
        }else if(str1 == '\0' && str2 != '\0'){
                return str2;
        }else if(str1 != '\0' && str2 == '\0'){
                return str1;
        }
        // const char str[10] = "string";        //try "string", "string\0", and "\0"
        // p = str;
        int strLength1 = string_length(str1);
        int strLength2 = string_length(str2);
        int totalLength = strLength1 + strLength2 + 1;        //plus one because null character

        char * combinedStr = malloc(totalLength*sizeof(char));


        //printf("Total length required to malloc is %d\n", totalLength);

        p = str1;

        for (int i = 0; i < strLength1; i++) //cannot do string_length(str1), since str1 is dynamic, strlen(str1) is smart and can work 
        {

                *(combinedStr+i) = *(p+i);

        }
        
        p = str2;

        //combineStr starts at index = strLength1
        for (int i = 0; i < strLength2; i++)
        {       
                combinedStr[strLength1+i] = p[i];

                //technically don't need but better be explicit :)
                if(i==strLength2-1){
                        *(combinedStr+strLength1+i+1) = '\0';   //append the null terminator character to make it an official string
                }
        }

        return combinedStr;
}

int string_length(const char * const str){
        int length = 0;
        char *p;
        p = str;
        
        //alternate way to iterate, without any library
        while(p != NULL && *p != '\0'){
                // printf("%c", *(p));
                length++;
                p++;  //cannot iterate with str since it's defined as const therefore read-only parameter
                //if you use str to iterate, you get segmentation fault:
                //https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
                if(*p == '\0'){
                        //printf("\n");
                        int i = 0;
                }
        }

        //printf("Testing string_length(): %d\n", length);

        return length;
}

void print_string_char_by_char(const char * const str){
        int string_length = strlen(str);
        char *p;
        p = str;
        //one way to iterate
        for (size_t i = 0; i < string_length; i++)
        {
                printf("%c", *(p+i));
                if(*(p+i+1)=='\0'){
                        printf("\n");
                }
        }

        //alternate way to iterate, without any library
        while(p != NULL && *p != '\0'){
                printf("%c", *(p));
                p++;
                if(*p == '\0'){
                        printf("\n");
                }
        }
}

void testcase1_twoNormalStrings(const char * str1, const char * str2){
        printf("Running test case 1: %s + %s = ", str1, str2);
        printf("%s\n", my_strcat(str1, str2));
        //print_string_char_by_char(my_strcat(str1, str2));     //print string twice with two different approaches
}

void testcase2_oneNormalStringOneNullChar(const char * str1, const char * str2){
        printf("Running test case 2: %s + '\\0' = ", str1);
        printf("%s\n", my_strcat(str1, str2));
        //print_string_char_by_char(my_strcat(str1, str2));     //print string twice with two different approaches
}

void testcase3_oneNullCharOneNormalString(const char * str1, const char * str2){
        printf("Running test case 3: '\\0' + %s = ", str2);
        printf("%s\n", my_strcat(str1, str2));
        //print_string_char_by_char(my_strcat(str1, str2));     //print string twice with two different approaches
}

void testcase4_twoNullChars(const char * str1, const char * str2){
        printf("Running test case 4: '\\0' + '\\0' = ");
        printf("%s\n", my_strcat(str1, str2));
        //print_string_char_by_char(my_strcat(str1, str2));     //print string twice with two different approaches
}

void testcase5_twoStringsWithSpecialChars(const char * str1, const char * str2){
        printf("Running test case 5: %s + %s = ", str1, str2);
        printf("%s\n", my_strcat(str1, str2));
        //print_string_char_by_char(my_strcat(str1, str2));     //print string twice with two different approaches
}
