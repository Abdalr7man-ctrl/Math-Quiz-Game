#include <iostream>
using namespace std;

const int MAX_INPUT_CHARS = 1000;

enum enQuestionLevel {Easy, Med, Hard, Mix};
enum enOperationType {Add, Sub, Mul, Div, MixOperation};
// struct 
// {
// };

int randomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int readPositiveNumber(string message, int from, int to)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(MAX_INPUT_CHARS, '\n');
        }
    } while (number < from || number > to);
    return number;
}

int HowManyQuestions()
{
    int questionNumber = readPositiveNumber("How Many Questions do you want to answer? ", 1, 500);
    return questionNumber;
}

enQuestionLevel QuestionLevel()
{
    short questionLevel = readPositiveNumber("Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ", 1, 4);
    return (enQuestionLevel)questionLevel;
}

enOperationType OperationType()
{
    short operationType = readPositiveNumber("Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ", 1, 5);
    return (enOperationType)operationType;
}

void showQuestion(int number1, int number2, enOperationType type)
{
    string operation = "";
    switch (type)
    {
    case Add: operation = "+"; break;
    case Sub: operation = "-"; break;
    case Mul: operation = "*"; break;
    case Div: operation = "/"; break;
    default: break;
    }
    cout << number1 << endl;
    cout << number2 << operation << endl;
    cout << "\n_______________________\n";
}

int questionAnswer(int number1, int number2, enOperationType type)
{
    switch (type)
    {
    case Add: return number1 + number2;
    case Sub: return number1 - number2;
    case Mul: return number1 * number2;
    case Div: return number1 / number2;
    }
    return 0;
}

void showRightAnswer()
{
    cout << "Right Answer :-)\n\n";
}

void showWrongAnswer(int rightAnswer)
{
    cout << "Wrong Answer :-(\n";
    cout << "The right Answer is : " << rightAnswer << "\n\n";
}

void easyQuestion(enOperationType type, int& rightAnswer)
{
    int answer;
    int number1 = randomNumber(1, 10);
    int number2 = randomNumber(1, 10);
    showQuestion(number1, number2, type);
    cin >> answer;
    if (answer == questionAnswer(number1, number2, type))
        {showRightAnswer(); rightAnswer++;}
    else
        showWrongAnswer(questionAnswer(number1, number2, type));
}

void medQuestion(enOperationType type, int& rightAnswer)
{
    int answer;
    int number1 = randomNumber(1, 50);
    int number2 = randomNumber(1, 50);
    showQuestion(number1, number2, type);
    cin >> answer;
    if (answer == questionAnswer(number1, number2, type))
        {showRightAnswer(); rightAnswer++;}
    else
        showWrongAnswer(questionAnswer(number1, number2, type));
}

void hardQuestion(enOperationType type, int& rightAnswer)
{
    int answer;
    int number1 = randomNumber(20, 100);
    int number2 = randomNumber(20, 100);
    showQuestion(number1, number2, type);
    cin >> answer;
    if (answer == questionAnswer(number1, number2, type))
        {showRightAnswer(); rightAnswer++;}
    else
        showWrongAnswer(questionAnswer(number1, number2, type));
}

void mixQuestion(enOperationType type, int& rightAnswer)
{
    enQuestionLevel randomQuestion[3] = {Easy, Med, Hard};
    enQuestionLevel myQuestion = randomQuestion[randomNumber(0, 2)];
    if (myQuestion == Easy)
        easyQuestion(type, rightAnswer);
    if (myQuestion == Med)
        medQuestion(type, rightAnswer);
    if (myQuestion == Hard)
        hardQuestion(type, rightAnswer);
}

void question(enQuestionLevel questionLevel, enOperationType operationType, int& RightAnswer)
{
    if (operationType == MixOperation)
    {
        enOperationType randomOperation[4] = {Add, Sub, Mul, Div};
        operationType = randomOperation[randomNumber(0, 3)];
    }
    if (questionLevel == Easy)
        easyQuestion(operationType, RightAnswer);
    else if (questionLevel == Med)
        medQuestion(operationType, RightAnswer);
    else if (questionLevel == Hard)
        hardQuestion(operationType, RightAnswer);
    else if (questionLevel == Mix)
        mixQuestion(operationType, RightAnswer);
}

void finalResult(int numberOfQuestion, enQuestionLevel questionLevel, enOperationType operationType, int rightAnswers)
{
    cout << "\n__________________________\n\n";
    cout << "Final Result is PASS :-)";
    cout << "\n__________________________\n";
    cout << "Number of Question    : " << numberOfQuestion << endl;
    cout << "Question Level        : " << questionLevel << endl;
    cout << "Operation Type        : " << operationType << endl;
    cout << "Number of Right Answer: " << rightAnswers << endl;
    cout << "Number of Wrong Answer: " << numberOfQuestion - rightAnswers << endl;
}

bool playAgain()
{
    string answer;
    cout << "Do you want to play again? Y/N? ";
    cin >> answer;
    return (answer  == "y" || answer == "Y");
}

void Exam()
{
    do
    {
        int questionNumber = HowManyQuestions();
        int rightAnswers = 0;
        enQuestionLevel questionLevel = QuestionLevel();
        enOperationType questionType = OperationType();
        for (int i = 1; i <= questionNumber; i++)
        {
            cout << "Question [" << i << "/" << questionNumber << "]\n\n";
            question(questionLevel, questionType, rightAnswers);
        }
        finalResult(questionNumber, questionLevel, questionType, rightAnswers);
    } while (playAgain());
}

int main()
{
    srand(time(NULL));

    // Operation type will == the Operation in the question
    Exam();

    return 0;
}
