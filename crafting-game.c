#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Function to check if string contains substring
//I didn't like strstr because it didn't work for certain strings
bool contains(char* haystack, char* needle){
    //Establishs the count which keeps track of needle index
    int count = 0;
    int baseCount;
    //Increments count past any spaces characters
    while(needle[count] == ' '){
        count++;
    }
    baseCount = count;
    int k;
    for(k = 0; k < strlen(haystack); k++){
        //Increments count if letters match; otherwise resets count to base
        if(haystack[k] == needle[count]){
            count++;
        }else{
            count = baseCount;
        }
        //Returns true if count has become as long as needle because it means
        //we went through every letter
        if(count >= strlen(needle)){
            return true;
        }
    }
    //Returns false to signify not finding the word
    return false;
}

//Function specific for this program that finds text between a prequisite string and delimiter, ignoring '>'
char* find(char* base, char delimiter, char* prereq, char* output){
    //Establishs the count which keeps track of needle index
    int count = 0;
    int baseCount;
    //Increments count past any blank characters
    while(prereq[count] == ''){
        count++;
    }
    baseCount = count;
    int k;
    bool keepTrack = false;
    //Loops through al of base
    for(k = 0; k < strlen(base); k++){
        
        //Similar to contains as it looks for a substring in the string
        if(count >= strlen(prereq)){
            keepTrack = true;
        }
        if(base[k] == prereq[count]){
            count++;
        }else{
            count = baseCount;
        }
        //If substring has been found and the character is the delimiter, return ""
        if(keepTrack && base[k] == delimiter){
            return "";
        }
        //Adjusts the output to have the text it needs in it
        if(keepTrack && base[k] != '>'){
            char conversion[2] = {base[k], '\0'};
            strcat(output, conversion);
        }
    }
}

//Main function that crafts items together
char* craft(char* inventory, char* item1, char* item2, char* recipes){
    //Checks that items are in the inventory
    if(strstr(inventory, item1) == NULL || strstr(inventory, item2) == NULL){
        return "\nAn error since you don't have those items/they don't exist!\n";
    }
    
    //Makes the key
    char complete_key[20] = {'\0'};
    strcat(complete_key, item1);
    strcat(complete_key, ":");
    strcat(complete_key, item2);

    //Makes the reverse to check both possibilities
    char complete_reverse_key[20] = {'\0'};
    strcat(complete_reverse_key, item2);
    strcat(complete_reverse_key, ":");
    strcat(complete_reverse_key, item1);
    
    //Initializes final_item to eventually be added to inventory
    char final_item[20] = {'\0'};
    
    //Finds the output of the recipe based on which key is correct
    if(contains(recipes, complete_key)){
        find(recipes, ';', complete_key, final_item);
    }else if(contains(recipes, complete_reverse_key)){
        find(recipes, ';', complete_reverse_key, final_item);
    }else{
        //If no keys were correct, return an error
        return "\nAn error since those items aren't craftable together!\n";
    }
    //If the user already has an item, return an error
    if(contains(inventory, final_item)){
        return "\nYou already have the item!\n";
    }else{
        //Add the item to inventory and return
        strcat(inventory, ", ");
        strcat(inventory, final_item);
        return "";
    }
    
}

//This game will involve crafting until you get a fruit
int main() {
    //Initializes important variables
    char inventory[51] = {0};
    strcat(inventory, "rock, wood");

    //Every possible recipe
    char recipes[120] = "rock:wood>axe;axe:rock>pickaxe;pickaxe:rock>metal;axe:wood>seed;wood:metal>shovel;shovel:rock>dirt;dirt:seed>fruit";

    //Ending item
    char needle[] = "fruit";
    
    //Loops through until we have fruit in our inventory
    while(strstr(inventory, needle) == NULL){
        //Prints out inventory
        printf("\nInventory: ");
        printf("%s", inventory);
        printf("\n");
        
        //Look for item1
        char response1[30];
        printf("\nEnter item1: \n");
        scanf("%s", response1);

        //Look for item 2
        char response2[30];
        printf("\nEnter item2: \n");
        scanf("%s", response2);

        //Craft and print out any error message
        printf("%s", craft(inventory, response1, response2, recipes));
    }
    
    //Win message displays
    printf("\nYou won because you found the fruit!");
    
    return 0;
}
