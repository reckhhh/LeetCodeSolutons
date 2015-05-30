/*
 Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button to reset your code definition. 

Tags: Two Pointers, String
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
     char* hay;
     char* nee;

     if (*needle == '\0')
        return (char*)haystack;
     if (*haystack == '\0' && *needle != '\0')
        return NULL;
     if (*haystack == '\0' && *needle == '\0')
        return (char*)haystack;

     for (; *haystack != '\0'; ++haystack)
     {
           for (; *haystack != *needle; ++haystack)
           {
               if (*haystack == '\0')
                  return NULL;
           }
           
           hay = haystack;
           nee = needle;
            
           while (*nee++ == *hay++)
           {
               if (*nee == '\0')
                   return (char*)haystack;
               if (*hay == '\0')
                   return NULL; 
           }
     }
     return NULL;
    }
};
