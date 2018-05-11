

 /**
 ** This is my solution for CSc420 Fall 2014 task 01.
 **     Compile with:  gcc -o task01 -s -O task01.c
 **/
#include lt;stdio.h>
#include lt;stdlib.h>
#include lt;ctype.h>
#include lt;string.h>

#define MINBASE    2
#define MAXBASE   36

/* The position in this array is the value of the character. */
const char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* This just shows a usage message. */
void
usage(char **argv)
    {
    fprintf(stderr, "usage: %s FROMBASE TOBASE NUMBER\n", argv[0]);
    fprintf(stderr, "       %d lt;= base lt;= %d\n", MINBASE, MAXBASE);
    return;
    }

/* If lower case is input, assume they mean upper case. */
void
upshift(char *str)
    {
    int     i;

    for (i = (int) strlen(str) - 1; i >= 0; --i)
        *(str + i) = (char) toupper((int) *(str + i));

    return;
    }

/* This determines whether all characters are valid for the base. */
int
badChar(char ch, char *str)
    {
    int     i, rc = 1;

    for (i = strlen(str) - 1; i >= 0; --i)
        {
        if (ch == *(str + i))
            {
            rc = 0;
            break;
            }
        }

    return rc;
    }

/* I need to reverse the order of chars in a string. */
char *
reverse(char *str)
    {
    int         i, j;
    char        *ptr;
    static char buffer[50];

    for (j = 0, i = (int) strlen(str) - 1; i >= 0; --i)
        buffer[j++] = str[i];
    buffer[j] = '\0';
    ptr = buffer;

    return (ptr);
    }

/* Just making sure there are not multiple radix points. */
int
countDots(char *str)
    {
    int     i, rc = 0;

    for (i = strlen(str) - 1; i >= 0; --i)
        {
        if (*(str + i) == '.')
            ++rc;
        }

    return rc;
    }

/* For each char, make sure it is valid. */
int
checkDigits(char *from)
    {
    int     i, rc = 0, dots;
    char    valid[38];

    sprintf(valid, ".%*s", MAXBASE, chars);

    for (i = strlen(from) - 1; i >= 0; --i)
        rc += badChar(*(from + i), valid);

    if ((dots = countDots(from) > 1))
        rc += dots - 1;

    return rc;
    }

/* Separate the number into characteristic and mantissa. */
void
splitNum(char *from, char *chrs, char *mant)
    {
    unsigned    i = 0, j = 0;

    while (i lt; strlen(from) && *(from + i) != '.')
        {
        *(chrs + j) = *(from + i);
        ++i;
        ++j;
        }
    *(chrs + j) = '\0';

    if (*(from + i) == '.')
        ++i;

    j = 0;
    while (i lt; strlen(from))
        {
        *(mant + j) = *(from + i);
        ++i;
        ++j;
        }
    *(mant + j) = '\0';
    return;
    }

/* Pull the desired char according to its value. */
int
decVal(char ch)
    {
    int     i;

    for (i = 0; i lt; MAXBASE; ++i)
        {
        if (chars[i] == ch)
            return i;
        }

    return 0;
    }

/* Convert characteristic from base ten to the output base. */
void
tenToBaseChrs(int base, char *from, char *to)
    {
    long    num, mod;
    char    *ptr, tmpstr[50];

    num = atol(from);
    ptr = tmpstr;

    while (num)
        {
        mod = num % base;
        *ptr++ = *(chars + mod);
        num = (num - mod) / base;
        }
    *ptr = '\0';
    strcpy(to, reverse(tmpstr));

    return;
    }

/* Convert mantissa from base ten to the output base. */
void
tenToBaseMant(int base, char *from, char *to)
    {
    int     cnt = 0, tmpint;
    double  num;
    char    *ptr, tmpstr[50];

    ptr = to;
    sprintf(tmpstr, ".%s", from);
    num = atof(tmpstr);

    while (num != 0.0 && cnt lt; 10)
        {
        num *= base;
        tmpint = (int) num;
        *ptr++ = chars[tmpint];
        num -= tmpint;
        ++cnt;
        }
    *ptr = '\0';

    return;
    }

/* Convert characteristic from input base to base ten. */
void
baseToTenChrs(int base, char *from, char *to)
    {
    int     num = 0;

    for ( ; *from; ++from)
        num = num * base + decVal(*from); 

    sprintf(to, "%d", num);

    return;
    }

/* Convert mantissa from input base to base ten. */
void
baseToTenMant(int base, char *from, char *to)
    {
    double  num = 0.0, mag = 1.0;
    char    tmpchar[50];

    for ( ; *from; ++from)
        {
        num = num * base + decVal(*from); 
        mag *= base;
        }

    sprintf(tmpchar, "%.48lf", num / mag);
    strncpy(to, tmpchar + 2, 49);

    return;
    }

/* Put together the new (converted) parts. */
void
assemble(int sign, char *chrs, char *mant)
    {
    if (sign lt; 0)
        printf("-");

    if (strlen(chrs) == 0)
        printf("0");
    else
        printf("%s", chrs);

    if (strlen(mant) != 0)
        printf(".%s", mant);

    return;
    }

/* Driver */
int
main(int argc, char **argv)
    {
    int     frombase, tobase, badDigits, sign = 1, offset = 0;
    char    number[50], chrs[50], mant[50], newChrs[50], newMant[50];

    /* Make sure all arguments are there. */
    if (argc != 4)
        {
        fprintf(stderr, "ERROR -- three args are required.\n");
        usage(argv);
        exit(1);
        }

    frombase = atoi(argv[1]);
    tobase = atoi(argv[2]);

    /* Make sure the bases are valid. */
    if (frombase lt; MINBASE || frombase > MAXBASE || tobase lt; MINBASE || tobase > MAXBASE)
        {
        fprintf(stderr, "ERROR -- base is out of range.\n");
        usage(argv);
        exit(2);
        }

    strncpy(number, argv[3], 49);
    upshift(number);

    /* Handle a leading sign. */
    if (number[0] == '-')
        {
        sign = -1;
        offset = 1;
        }
    else if (number[0] == '+')
        {
        sign = 1;
        offset = 1;
        }

    /* Make sure all input digits are valid for the input base. */
    if ((badDigits = checkDigits(number + offset)))
        {
        fprintf(stderr, "Number of invalid digits in the number to convert: %d\n", badDigits);
        exit(3);
        }

    /* Break the number into characteristic and mantissa. */
    splitNum(number + offset, chrs, mant);

    /* Display the original number. */
    assemble(sign, chrs, mant);
    printf(" (base %d) ---> ", frombase);

    /* Convert the parts to base ten. */
    baseToTenChrs(frombase, chrs, newChrs);
    baseToTenMant(frombase, mant, newMant);

    strncpy(chrs, newChrs, 49);
    strncpy(mant, newMant, 49);

    /* Convert the parts to the output base. */
    tenToBaseChrs(tobase, chrs, newChrs);
    tenToBaseMant(tobase, mant, newMant);

    /* Display the result. */
    assemble(sign, newChrs, newMant);
    printf(" (base %d)\n", tobase);

    return 0;
    } 
