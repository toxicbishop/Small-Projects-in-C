//header files for standard input output functions
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>    // Required for time()
#include<windows.h> // For Sleep

// Simple Quiz Game in C

int main (){
    // Array of 50 general knowledge questions
    char questions[][100] = {
        "What is the capital of France?",
        "What is 2 + 2?",
        "What is the largest planet in our solar system?",
        "What is the capital of Italy?",
        "What is the chemical symbol for water?",
        "Who wrote 'Romeo and Juliet'?",
        "What is the smallest prime number?",
        "What planet is known as the Red Planet?",
        "What is the hardest natural substance on Earth?",
        "Who painted the Mona Lisa?",
        "What is the speed of light in vacuum?",
        "Which continent is the Sahara Desert located in?",
        "Who is known as the father of computers?",
        "What is the largest mammal?",
        "Which country is known as the Land of the Rising Sun?",
        "What is the boiling point of water?",
        "Who discovered penicillin?",
        "What is the main language spoken in Brazil?",
        "Which ocean is the largest?",
        "What is the currency of Japan?",
        "Who invented the telephone?",
        "What is the tallest mountain in the world?",
        "Which planet is closest to the sun?",
        "What is the largest organ in the human body?",
        "Who is the author of 'Harry Potter'?",
        "What is the national sport of Canada?",
        "Which element has the chemical symbol 'O'?",
        "What is the capital of Australia?",
        "Who painted the ceiling of the Sistine Chapel?",
        "What is the smallest country in the world?",
        "What is the longest river in the world?",
        "Who was the first man on the moon?",
        "What is the largest continent?",
        "What is the main ingredient in guacamole?",
        "Which country gifted the Statue of Liberty to the USA?",
        "What is the chemical symbol for gold?",
        "Who is known as the Iron Lady?",
        "What is the capital of Egypt?",
        "Which animal is known as the King of the Jungle?",
        "What is the largest ocean on Earth?",
        "Who wrote 'Pride and Prejudice'?",
        "What is the square root of 64?",
        "Which gas do plants absorb from the atmosphere?",
        "What is the capital of Spain?",
        "Who is the Greek god of the sea?",
        "What is the largest island in the world?",
        "What is the main ingredient in sushi?",
        "Who invented the light bulb?",
        "What is the capital of Germany?",
        "Which country is famous for tulips?",
        "What is the chemical symbol for sodium?",
        "Who is the founder of Microsoft?",
        "What is the largest desert in the world?",
        "What is the capital of Russia?",
        "Which bird is known for its beautiful tail?",
        "What is the hardest known substance?",
        "Who is the author of 'The Odyssey'?",
        "What is the capital of China?",
        "Which planet is known for its rings?",
        "What is the national flower of India?",
        "Who discovered gravity?",
        "What is the capital of Canada?",
        "Which country is known as the Land of the Midnight Sun?",
        "What is the chemical symbol for iron?",
        "Who is the current President of the USA (2026)?",
        "What is the largest lake in the world?",
        "What is the capital of South Africa?",
        "Which animal is the symbol of WWF?",
        "What is the main ingredient in hummus?",
        "Who is the author of 'The Hobbit'?",
        "What is the capital of Argentina?",
        "Which country is known for the Eiffel Tower?",
        "What is the chemical symbol for silver?"
    };

    // Array of options for each question (A/B/C/D)
    char options[][4][50] = {
        {"A. Berlin\n", "B. Madrid\n", "C. Paris\n", "D. Rome\n"},
        {"A. 3\n", "B. 4\n", "C. 5\n", "D. 6\n"},
        {"A. Earth\n", "B. Jupiter\n", "C. Mars\n", "D. Saturn\n"},
        {"A. Venice\n", "B. Milan\n", "C. Naples\n", "D. Rome\n"},
        {"A. CO2\n", "B. H2O\n", "C. O2\n", "D. NaCl\n"},
        {"A. Charles Dickens\n", "B. William Shakespeare\n", "C. Mark Twain\n", "D. Jane Austen\n"},
        {"A. 0\n", "B. 1\n", "C. 2\n", "D. 3\n"},
        {"A. Venus\n", "B. Mars\n", "C. Jupiter\n", "D. Saturn\n"},
        {"A. Gold\n", "B. Iron\n", "C. Diamond\n", "D. Silver\n"},
        {"A. Vincent van Gogh\n", "B. Pablo Picasso\n", "C. Leonardo da Vinci\n", "D. Claude Monet\n"},
        {"A. 300,000 km/s\n", "B. 150,000 km/s\n", "C. 450,000 km/s\n", "D. 600,000 km/s\n"},
        {"A. Africa\n", "B. Asia\n", "C. Europe\n", "D. Australia\n"},
        {"A. Charles Babbage\n", "B. Alan Turing\n", "C. Bill Gates\n", "D. Steve Jobs\n"},
        {"A. Elephant\n", "B. Blue Whale\n", "C. Giraffe\n", "D. Hippopotamus\n"},
        {"A. China\n", "B. Japan\n", "C. Korea\n", "D. Thailand\n"},
        {"A. 90°C\n", "B. 100°C\n", "C. 80°C\n", "D. 120°C\n"},
        {"A. Alexander Fleming\n", "B. Marie Curie\n", "C. Louis Pasteur\n", "D. Isaac Newton\n"},
        {"A. Spanish\n", "B. Portuguese\n", "C. French\n", "D. English\n"},
        {"A. Atlantic\n", "B. Indian\n", "C. Pacific\n", "D. Arctic\n"},
        {"A. Yen\n", "B. Dollar\n", "C. Euro\n", "D. Peso\n"},
        {"A. Alexander Graham Bell\n", "B. Thomas Edison\n", "C. Nikola Tesla\n", "D. Albert Einstein\n"},
        {"A. K2\n", "B. Everest\n", "C. Kilimanjaro\n", "D. Elbrus\n"},
        {"A. Mercury\n", "B. Venus\n", "C. Earth\n", "D. Mars\n"},
        {"A. Heart\n", "B. Skin\n", "C. Liver\n", "D. Brain\n"},
        {"A. J.K. Rowling\n", "B. Enid Blyton\n", "C. Roald Dahl\n", "D. Suzanne Collins\n"},
        {"A. Ice Hockey\n", "B. Soccer\n", "C. Baseball\n", "D. Basketball\n"},
        {"A. Oxygen\n", "B. Hydrogen\n", "C. Nitrogen\n", "D. Helium\n"},
        {"A. Sydney\n", "B. Melbourne\n", "C. Canberra\n", "D. Brisbane\n"},
        {"A. Michelangelo\n", "B. Raphael\n", "C. Donatello\n", "D. Leonardo\n"},
        {"A. Monaco\n", "B. Vatican City\n", "C. San Marino\n", "D. Liechtenstein\n"},
        {"A. Nile\n", "B. Amazon\n", "C. Yangtze\n", "D. Mississippi\n"},
        {"A. Yuri Gagarin\n", "B. Neil Armstrong\n", "C. Buzz Aldrin\n", "D. John Glenn\n"},
        {"A. Africa\n", "B. Asia\n", "C. Europe\n", "D. Australia\n"},
        {"A. Tomato\n", "B. Avocado\n", "C. Onion\n", "D. Pepper\n"},
        {"A. France\n", "B. Germany\n", "C. Italy\n", "D. Spain\n"},
        {"A. Au\n", "B. Ag\n", "C. Fe\n", "D. Cu\n"},
        {"A. Margaret Thatcher\n", "B. Angela Merkel\n", "C. Indira Gandhi\n", "D. Golda Meir\n"},
        {"A. Cairo\n", "B. Alexandria\n", "C. Giza\n", "D. Luxor\n"},
        {"A. Lion\n", "B. Tiger\n", "C. Elephant\n", "D. Bear\n"},
        {"A. Atlantic\n", "B. Indian\n", "C. Pacific\n", "D. Arctic\n"},
        {"A. Jane Austen\n", "B. Emily Bronte\n", "C. Charlotte Bronte\n", "D. Louisa May Alcott\n"},
        {"A. 6\n", "B. 7\n", "C. 8\n", "D. 9\n"},
        {"A. Oxygen\n", "B. Carbon Dioxide\n", "C. Nitrogen\n", "D. Hydrogen\n"},
        {"A. Madrid\n", "B. Barcelona\n", "C. Seville\n", "D. Valencia\n"},
        {"A. Zeus\n", "B. Hades\n", "C. Poseidon\n", "D. Apollo\n"},
        {"A. Greenland\n", "B. Australia\n", "C. Borneo\n", "D. Madagascar\n"},
        {"A. Rice\n", "B. Fish\n", "C. Seaweed\n", "D. Soy Sauce\n"},
        {"A. Thomas Edison\n", "B. Nikola Tesla\n", "C. Alexander Graham Bell\n", "D. Albert Einstein\n"},
        {"A. Munich\n", "B. Berlin\n", "C. Hamburg\n", "D. Frankfurt\n"},
        {"A. Netherlands\n", "B. Belgium\n", "C. France\n", "D. Denmark\n"},
        {"A. Na\n", "B. K\n", "C. Ca\n", "D. Mg\n"},
        {"A. Bill Gates\n", "B. Steve Jobs\n", "C. Mark Zuckerberg\n", "D. Larry Page\n"},
        {"A. Sahara\n", "B. Gobi\n", "C. Kalahari\n", "D. Arabian\n"},
        {"A. Moscow\n", "B. St. Petersburg\n", "C. Novosibirsk\n", "D. Kazan\n"},
        {"A. Peacock\n", "B. Eagle\n", "C. Parrot\n", "D. Swan\n"},
        {"A. Diamond\n", "B. Gold\n", "C. Silver\n", "D. Iron\n"},
        {"A. Homer\n", "B. Virgil\n", "C. Sophocles\n", "D. Plato\n"},
        {"A. Beijing\n", "B. Shanghai\n", "C. Guangzhou\n", "D. Shenzhen\n"},
        {"A. Saturn\n", "B. Jupiter\n", "C. Uranus\n", "D. Neptune\n"},
        {"A. Rose\n", "B. Lotus\n", "C. Lily\n", "D. Jasmine\n"},
        {"A. Isaac Newton\n", "B. Albert Einstein\n", "C. Galileo Galilei\n", "D. Stephen Hawking\n"},
        {"A. Ottawa\n", "B. Toronto\n", "C. Vancouver\n", "D. Montreal\n"},
        {"A. Norway\n", "B. Sweden\n", "C. Finland\n", "D. Denmark\n"},
        {"A. Fe\n", "B. Ir\n", "C. In\n", "D. I\n"},
        {"A. Joe Biden\n", "B. Donald Trump\n", "C. Kamala Harris\n", "D. Barack Obama\n"},
        {"A. Caspian Sea\n", "B. Lake Superior\n", "C. Lake Victoria\n", "D. Lake Baikal\n"},
        {"A. Pretoria\n", "B. Cape Town\n", "C. Johannesburg\n", "D. Durban\n"},
        {"A. Panda\n", "B. Tiger\n", "C. Elephant\n", "D. Lion\n"},
        {"A. Chickpeas\n", "B. Lentils\n", "C. Beans\n", "D. Peas\n"},
        {"A. J.R.R. Tolkien\n", "B. C.S. Lewis\n", "C. J.K. Rowling\n", "D. George R.R. Martin\n"},
        {"A. Buenos Aires\n", "B. Santiago\n", "C. Lima\n", "D. Bogota\n"},
        {"A. France\n", "B. Italy\n", "C. Spain\n", "D. Germany\n"},
        {"A. Ag\n", "B. Au\n", "C. Si\n", "D. Sn\n"}
    };

    // Array of correct answers for each question (A/B/C/D)
    char answerskey[] = {
        'C','B','B','D','B','B','C','B','C','C','A','A','A','B','B','B','A','B','C','A',
        'A','B','A','B','A','A','A','C','A','B','A','B','B','B','A','A','A','A','A','A','C',
        'B','B','A','C','A','A','A','B','A','A'
    };

    // Explanations for correct answers (short reasons)
    const char *explanations[] = {
        "Paris is the capital of France.",
        "2 + 2 equals 4.",
        "Jupiter is the largest planet in the solar system.",
        "Rome is the capital of Italy.",
        "H2O is the chemical formula for water.",
        "William Shakespeare wrote 'Romeo and Juliet'.",
        "2 is the smallest prime number.",
        "Mars is known as the Red Planet because of iron oxide on its surface.",
        "Diamond is the hardest natural substance.",
        "Leonardo da Vinci painted the Mona Lisa.",
        "The speed of light in vacuum is approximately 300,000 km/s.",
        "The Sahara Desert is located in Africa.",
        "Charles Babbage is considered the father of computers.",
        "The blue whale is the largest mammal.",
        "Japan is called the Land of the Rising Sun.",
        "Water boils at 100°C at standard atmospheric pressure.",
        "Alexander Fleming discovered penicillin.",
        "Portuguese is the main language spoken in Brazil.",
        "The Pacific is the largest ocean.",
        "The Yen is the currency of Japan.",
        "Alexander Graham Bell is credited with inventing the telephone.",
        "Mount Everest is the tallest mountain above sea level.",
        "Mercury is the planet closest to the Sun.",
        "Skin is the largest organ of the human body.",
        "J.K. Rowling is the author of the Harry Potter series.",
        "Ice hockey is widely considered Canada's national sport.",
        "O is the chemical symbol for oxygen.",
        "Canberra is the capital of Australia.",
        "Michelangelo painted the ceiling of the Sistine Chapel.",
        "Vatican City is the smallest independent country in the world.",
        "The Nile is commonly cited as the longest river in the world.",
        "Neil Armstrong was the first man to walk on the Moon.",
        "Asia is the largest continent by area and population.",
        "Avocado is the main ingredient in guacamole.",
        "France gifted the Statue of Liberty to the United States.",
        "Au is the chemical symbol for gold.",
        "Margaret Thatcher was known as the Iron Lady.",
        "Cairo is the capital of Egypt.",
        "The lion is often referred to as the King of the Jungle.",
        "The Pacific Ocean is the largest ocean on Earth.",
        "Jane Austen wrote 'Pride and Prejudice'.",
        "The square root of 64 is 8.",
        "Plants absorb carbon dioxide (CO2) for photosynthesis.",
        "Madrid is the capital of Spain.",
        "Poseidon is the Greek god of the sea.",
        "Greenland is the largest island in the world.",
        "Fish/seafood are common main ingredients in sushi.",
        "Thomas Edison is credited with inventing the practical light bulb.",
        "Berlin is the capital of Germany.",
        "The Netherlands is famous for its tulips.",
        "Ag is the chemical symbol for silver."
    };

    int score = 0; // User's score
    // compute counts for safety and use the smallest to avoid overruns
    int questionsCount = sizeof(questions) / sizeof(questions[0]);
    int optionsCount = sizeof(options) / sizeof(options[0]);
    int answersCount = sizeof(answerskey) / sizeof(answerskey[0]);
    int explanationsCount = sizeof(explanations) / sizeof(explanations[0]);
    int totalQuestions = questionsCount;
    if(optionsCount < totalQuestions) totalQuestions = optionsCount;
    if(answersCount < totalQuestions) totalQuestions = answersCount;
    if(explanationsCount < totalQuestions) totalQuestions = explanationsCount;

    // Build an array of structs for safer access
    typedef struct {
        char question[128];
        char opts[4][64];
        char answer; // 'A'..'D'
        const char *explanation;
    } Question;

    Question quiz[100]; // max capacity (we will use totalQuestions)
    for(int i=0;i<totalQuestions;i++){
        strncpy(quiz[i].question, questions[i], sizeof(quiz[i].question)-1);
        quiz[i].question[sizeof(quiz[i].question)-1] = '\0';
        for(int j=0;j<4;j++){
            strncpy(quiz[i].opts[j], options[i][j], sizeof(quiz[i].opts[j])-1);
            quiz[i].opts[j][sizeof(quiz[i].opts[j])-1] = '\0';
        }
        quiz[i].answer = answerskey[i];
        quiz[i].explanation = explanations[i];
    }

    // Inform user how many questions will be asked
    printf("(Using %d questions)\n", totalQuestions);

    // Show existing high score if available
    const char *hsfile = "highscore.txt";
    int bestScore = -1;
    char bestName[64] = "";
    FILE *hf = fopen(hsfile, "r");
    if(hf){
        if(fscanf(hf, "%d\n", &bestScore) == 1){
            if(fgets(bestName, sizeof(bestName), hf)){
                // trim newline
                size_t ln = strlen(bestName);
                if(ln>0 && bestName[ln-1]=='\n') bestName[ln-1]='\0';
            }
        }
        fclose(hf);
    }
    if(bestScore >= 0) printf("High score: %d by %s\n", bestScore, bestName);

    // Ask user if they want to shuffle questions
    char line[128];
    int doShuffle = 0;
    printf("Shuffle questions? (y/N): ");
    if(fgets(line, sizeof(line), stdin)){
        if(line[0]=='y' || line[0]=='Y') doShuffle = 1;
    }

    // Prepare order array and shuffle if requested
    int order[100];
    for(int i=0;i<totalQuestions;i++) order[i]=i;
    if(doShuffle){
        srand((unsigned)time(NULL)); // FIXED: use time(NULL) instead of time((time_t*)0)
        for(int i=totalQuestions-1;i>0;i--){
            int r = rand() % (i+1);
            int tmp = order[i]; order[i]=order[r]; order[r]=tmp;
        }
    }

    printf("Welcome to the Quiz Game!\n");

    // Loop through each question in order
    for(int qIdx=0;qIdx<totalQuestions;qIdx++){
        int i = order[qIdx];
        printf("\nQ%d. %s\n", qIdx+1, quiz[i].question);
        for(int j=0;j<4;j++) printf("%s", quiz[i].opts[j]);

        char answerChar='\0';
        // Prompt until valid input (A-D)
        while(1){
            printf("Enter your answer (A-D): ");
            if(!fgets(line, sizeof(line), stdin)) { answerChar='\0'; break; }
            // find first non-space
            int k=0; while(line[k] && isspace((unsigned char)line[k])) k++;
            if(!line[k]) continue;
            answerChar = line[k];
            if(answerChar>='a' && answerChar<='z') answerChar = answerChar - 'a' + 'A';
            if(answerChar>='A' && answerChar<='D') break;
            printf("Invalid option. Please enter A, B, C, or D.\n");
        }

        if(answerChar == quiz[i].answer){
            printf("Correct!\n");
            score++;
        } else {
            int userIdx = -1;
            if(answerChar>='A' && answerChar<='D') userIdx = answerChar - 'A';
            if(userIdx>=0 && userIdx<4) printf("Wrong! You chose option %c: %s", answerChar, quiz[i].opts[userIdx]);
            else printf("Wrong! You entered an invalid option: %c\n", answerChar);
            int correctIdx = quiz[i].answer - 'A';
            if(correctIdx>=0 && correctIdx<4) printf("Correct answer: option %c: %s", quiz[i].answer, quiz[i].opts[correctIdx]);
            printf("Reason: %s\n", quiz[i].explanation);
        }
    }

    // Print final score
    printf("\nQuiz Over! Your total score is %d out of %d.\n", score, totalQuestions);

    // Print result classification in table format
    printf("\n---------------------------------------------\n");
    printf("|   Score Range   |     Classification      |\n");
    printf("---------------------------------------------\n");
    printf("|   48 - 50      |     Distinction         |\n");
    printf("|   40 - 47      |     First Class         |\n");
    printf("|   35 - 39      |     Second Class        |\n");
    printf("|   19 - 34      |     Pass                |\n");
    printf("|   0  - 18      |     Fail                |\n");
    printf("---------------------------------------------\n");

    // Print user's result
    if(score < 19) {
        printf("\nYour Result: Fail\n");
    } else if(score >= 48) {
        printf("\nYour Result: Distinction\n");
    } else if(score >= 40) {
        printf("\nYour Result: First Class\n");
    } else if(score >= 35) {
        printf("\nYour Result: Second Class\n");
    } else {
        printf("\nYour Result: Pass\n");
    }

    // Save high score if beaten
    if(score > bestScore){
        printf("\nNew high score! Enter your name: ");
        if(fgets(bestName, sizeof(bestName), stdin)){
            size_t ln = strlen(bestName); if(ln>0 && bestName[ln-1]=='\n') bestName[ln-1]='\0';
            FILE *wf = fopen(hsfile, "w");
            if(wf){
                fprintf(wf, "%d\n%s\n", score, bestName);
                fclose(wf);
                printf("High score saved.\n");
            } else {
                printf("Failed to save high score.\n");
            }
        }
    }

    return 0;
}