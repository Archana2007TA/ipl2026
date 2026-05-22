#include<stdio.h>
union decision
{
    unsigned char flags;

    struct 
    {
        unsigned int your_choice :1;
        unsigned int your_mothers_choice:1;
        unsigned int your_fathers_choice:1;
        unsigned int socially_acceptable:1;
        unsigned int financially_viable:1;
        unsigned int do_you_have_aptitude:1;
        unsigned int do_you_like_it:1;
        unsigned int decision:1;
    }field;
    
};
union decision input();
void make_decision(union decision *d);
void print_decision(union decision d);
void print_conclusion_based_on_flags(union decision d);
union decision input(){
    union decision d;
    unsigned int temp;

    printf("Your choice (0/1): ");
    scanf("%u",&temp);
    d.field.your_choice=temp;
    printf("Mother's choice (0/1): ");
    scanf("%u",&temp);
    d.field.your_mothers_choice=temp;
    printf("Father's choice (0/1): ");
    scanf("%u",&temp);
    d.field.your_fathers_choice=temp;
    printf("Socially acceptable (0/1): ");
    scanf("%u",&temp);
    d.field.socially_acceptable=temp;
    printf("Financially viable (0/1): ");
    scanf("%u",&temp);
    d.field.financially_viable=temp;
    printf("Do you have aptitude (0/1): ");
    scanf("%u",&temp);
    d.field.do_you_have_aptitude=temp;
    printf("Do you like it (0/1): ");
    scanf("%u",&temp);
    d.field.do_you_like_it=temp;
    
    d.field.decision=0;
    return d;
}
void make_decision(union decision *d){
    d->field.decision=d->field.your_choice && 
    d->field.socially_acceptable && 
    d->field.financially_viable && 
    d->field.do_you_have_aptitude &&
    d->field.do_you_like_it;
}
void print_decision(union decision d){
    printf("\n-----Decision Report-----\n");
    printf("Your choice:%u\n",d.field.your_choice);
    printf("Mother's choice:%u\n",d.field.your_mothers_choice);
    printf("Father's choice:%u\n",d.field.your_fathers_choice);
    printf("Socially acceptable:%u\n",d.field.socially_acceptable);
    printf("Financially viable:%u\n",d.field.financially_viable);
    printf("Aptitude:%u\n",d.field.do_you_have_aptitude);
    printf("You like it:%u\n",d.field.do_you_like_it);
    if(d.field.decision)
        printf("\nFinal decision: GO AHEAD!\n");
    else
        printf("\nFinal decision: RECONSIDER.\n");
}
void print_conclusion_based_on_flags(union decision d){
    printf("\nFalgs value=%u\n",d.flags);
    if(d.flags==255){
        printf("Perfecy aligment of all factors.\n");
    }
    else if(d.flags>100){
        printf("Most factors support the decision.\n");
    }
    else if(d.flags>50){
        printf("Mixed signals. Think carefully.\n");
    }
    else{
        printf("Many factors are against this decision.\n");
    }
}
int main(){
    union decision d;
    d=input();
    make_decision(&d);
    print_decision(d);
    print_conclusion_based_on_flags(d);
    return 0;
}