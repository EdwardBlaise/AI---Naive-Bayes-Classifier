#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"

/*struct element_data
{
    int i;
    char color[25];
    char engine[25];
    char origin[25];
    char liked[25];
};

typedef struct element_data elements;

enum TRAIT { COLOR = 1, ENGINE = 2, ORIGIN = 3, LIKED = 4 };

int find_all_with_trait_conditioned_by(elements data[], int length, 
                                       char * trait, enum TRAIT trait_id, 
                                       char * conditioned_by, enum TRAIT condition_id)
{
    int num = 0;

    for(int i = 0; i < length; i++)
    {
        switch (trait_id)
        {
            case COLOR:
                if (strcmp(data[i].color, trait) == 0 && strcmp(data[i].liked, conditioned_by) == 0)
                    num++;
                break;
            case ENGINE:
                if (strcmp(data[i].engine, trait) == 0 && strcmp(data[i].liked, conditioned_by) == 0)
                    num++;
                break;
            case ORIGIN:
                if (strcmp(data[i].origin, trait) == 0 && strcmp(data[i].liked, conditioned_by) == 0)
                    num++;
                break;
            case LIKED:
                if (strcmp(data[i].liked, trait) == 0 && strcmp(data[i].liked, conditioned_by) == 0)
                    num++;
                break;
            default:
                break;
        }
    }

    return num;
}
*/

int find_all_traits (char * data [] [10],   int n_data,
                     char * conditioned_by, int i_trait)
{
    int found = 0;

    for (int i = 0; i < n_data; i++)
    {
        if (strcmp (data [i] [i_trait], conditioned_by) == 0)
        {
            found += 1;
        }
    }

    return found;
}

int * find_all_with_traits_conditioned_by (char * data [] [10],     int n_data,
                                           char * traits [],        int n_traits,
                                           char * conditioned_by,   int i_trait)
{
    int * traits_found = malloc (sizeof (int) * n_traits);
    int found = 0;

    for (int i = 0; i < n_data; i++)
    {
        for (int j = 0; j < n_traits; j++)
        {
            if (strcmp (data [i] [j], traits [j]) == 0 
                && 
                strcmp (data [i] [i_trait], conditioned_by) == 0)
            {
                traits_found [found] += 1;
            }

            found += 1;
        }

        found -= 3;
    }        

    return traits_found;    
}


typedef char * string;                  

int main()
{
    /*elements data[10] = 
    {
        {1, "Red", "Sports", "Domestic", "Yes"},
        {2, "Red", "Sports", "Domestic", "No"},
        {3, "Red", "Sports", "Domestic", "Yes"},
        {4, "Yellow", "Sports", "Domestic", "No"},
        {5, "Yellow", "Sports", "Imported", "Yes"},
        {6, "Yellow", "SUV", "Imported", "No"},
        {7, "Yellow", "SUV", "Imported", "Yes"},
        {8, "Yellow", "SUV", "Domestic", "No"},
        {9, "Red", "SUV", "Imported", "No"},
        {10, "Red", "Sports", "Imported", "Yes"}
    };*/
    
    string data[10][10] =
    {
        {"Red", "Sports", "Domestic", "Yes"},
        {"Red", "Sports", "Domestic", "No"},
        {"Red", "Sports", "Domestic", "Yes"},
        {"Yellow", "Sports", "Domestic", "No"},
        {"Yellow", "Sports", "Imported", "Yes"},
        {"Yellow", "SUV", "Imported", "No"},
        {"Yellow", "SUV", "Imported", "Yes"},
        {"Yellow", "SUV", "Domestic", "No"},
        {"Red", "SUV", "Imported", "No"},
        {"Red", "Sports", "Imported", "Yes"}
    };

    int n_data = sizeof(data)/sizeof(data[0]);

    // If Ford Import Grey would be liked.
    // P (Yes | Ford, Import, Grey) = P (Ford, Import, Grey | Yes) P (Yes)    =     P (Ford | Yes) P (Import | Yes) P (Grey | Yes) P (Yes)
    //                                ------------------------------------          ------------------------------------------------------
    //                                      P (Ford, Import, Grey)                                    P (Ford) P (Import) P (Grey)

    /*for (int i = 0; i < 5; i++)
        printf("ID: %d - Make: %s - Origin: %s - Color: %s - Liked: %d\n", data[i].i, data[i].make, data[i].origin, data[i].color, data[i].liked);*/

    char * traits[] = { "Yellow", "SUV", "Imported" }; 

    char * condition = "No";

    int n_traits = sizeof(traits) / sizeof(traits[0]);

    int i_condition = 3;

    int trait = find_all_traits (data, n_data, condition, i_condition);

    int * discovered = find_all_with_traits_conditioned_by (data, n_data, 
                                                            traits, n_traits, 
                                                            condition, i_condition);

    printf("%s : %d\n\n", condition, trait);

    for(int i = 0; i < n_traits; i++)
        printf("%s : %d\n", traits[i], discovered[i]);
    
    printf("\n");

    getchar();

    return 0;
}