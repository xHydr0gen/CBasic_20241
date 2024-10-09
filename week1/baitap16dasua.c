#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 


const char *articles[] = {"the", "a", "one", "some", "any"};
const char *nouns[] = {"boy", "girl", "dog", "town", "car"};
const char *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
const char *prepositions[] = {"to", "from", "over", "under", "on"};

#define NUM_ARTICLES (sizeof(articles) / sizeof(articles[0]))
#define NUM_NOUNS (sizeof(nouns) / sizeof(nouns[0]))
#define NUM_VERBS (sizeof(verbs) / sizeof(verbs[0]))
#define NUM_PREPOSITIONS (sizeof(prepositions) / sizeof(prepositions[0]))

int get_random_index(int max) {
    return rand() % max;
}

void generate_sentence() {
    int article1_index = get_random_index(NUM_ARTICLES);
    int noun1_index = get_random_index(NUM_NOUNS);
    int verb_index = get_random_index(NUM_VERBS);
    int preposition_index = get_random_index(NUM_PREPOSITIONS);
    int article2_index = get_random_index(NUM_ARTICLES);
    int noun2_index = get_random_index(NUM_NOUNS);
    
    printf("%c%s %s %s %s %s %s.\n",
           toupper(articles[article1_index][0]), 
           articles[article1_index] + 1, 
           nouns[noun1_index],
           verbs[verb_index],
           prepositions[preposition_index],
           articles[article2_index],
           nouns[noun2_index]);
}

int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        generate_sentence();
    }

    return 0;
}










