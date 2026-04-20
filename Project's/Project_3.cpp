
#include <iostream> // مسؤولة عن عمليات الإدخال والإخراج الأساسية

#include <string> // تتيح استخدام النصوص والعمليات المتعلقة بها

#include <cmath> // توفر الدوال الرياضية المتقدمة مثل الجذور والعمليات الحسابية

#include <cstdlib> // تحتوي على دوال النظام وتوليد الأرقام العشوائية

#include <ctime> // تُستخدم للحصول على وقت النظام لضمان عشوائية الأرقام كل مرة

using namespace std;             

// ==========================================
// Enums & Structs                     
// ==========================================

// تعريف مستويات الصعوبة
enum enQuizzLevel {Easy = 1, Med = 2, Hard = 3, MixLevel = 4};   


// تعريف العمليات الرياضية
enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};  
  

// هيكل للسوال الواحد
struct stQuestions 
{
    enOperationType OperationType;
    enQuizzLevel QuizzLevel;
    int Number1 = 0;
    int Number2 = 0;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false; 
};

// هيكل للاختبار كامل
struct stQuizz
{
    stQuestions QuestionsList[100]; 
    enQuizzLevel QuestionsLevel; 
    enOperationType OperationType; 
    short NumberOfQuestions; 
    short NumberOfRightAnswer = 0; 
    short NumberOfWorngAnswer = 0; 
    bool isPass = true; 
};

// ==========================================

// Function Prototypes

// ==========================================

int RandomNumber(int From, int To); 
short ReadQuestionNumber(); 
enQuizzLevel ReadQuestionLevel(); 
enOperationType ReadOperationType(); 
enOperationType GetRandomOperationType(); 
int SimpleCalculator(int Number1, int Number2, enOperationType OpType); 
stQuestions GenerateQuestion(enQuizzLevel QuizzLevel, enOperationType OpType);
void GeneratQuizzQuestions(stQuizz &Quizz);
string GetOperationTypeSymbol(enOperationType OpType);
void PrintTheQestions(stQuizz &Quizz, short QustionsNumber);
int ReadQuestionAnswer();
void SetScreenColor(bool isRight);
void CorrectTheQuestionAnswer(stQuizz &Quizz, short QustionsNumber);
void AskAndCorrectQuestionsListAnswer(stQuizz &Quizz);
string GetFinalResultText(bool Pass);
string GetQustionsLevelText(enQuizzLevel QuestionLevel);
void PrintQuizzReults(stQuizz Quizz);
void ShowFinalQuizzScreen(stQuizz Quizz);
void ClearScreen();
void PlayMathGame();
void StartGame();
void DrawHeader(string Title);

// ==========================================

// Main Function

// ==========================================

int main()
{
    srand((unsigned)time(NULL));

    StartGame(); 

    return 0;
}
// ==========================================
// Function Definitions 
// ==========================================

// تقوم هذه الدالة برسم إطار جمالي ملون لعناوين الواجهة

void DrawHeader(string Title)
{
    cout << "\n\033[36m==================================================\n";
    cout << "\t\t" << Title << "\n"; 
    cout << "==================================================\033[0m\n";
}

// تولد رقماً عشوائياً ضمن نطاق محدد (من - إلى)ر

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// تطلب من المستخدم إدخال عدد الأسئلة وتتأكد أن العدد بين 1 و 100

short ReadQuestionNumber()
{
    short NumberOfQuestions;
    DrawHeader("MATH QUIZ GAME");
    do
    {
        cout << "\033[33m[?]\033[0m How Many Questions Do You Want (1-100)? : ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 || NumberOfQuestions > 100);

    return NumberOfQuestions;
}

// تعرض خيارات مستوى الصعوبة وتستقبل اختيار المستخدم

enQuizzLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    cout << "\033[33m[?]\033[0m Choose Level:\n";
    cout << "    [1] Easy\n    [2] Medium\n    [3] Hard\n    [4] Mix\n";

    do
    {
        cout << "Enter Choice: ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuizzLevel)QuestionLevel;
}

// تعرض أنواع العمليات الحسابية وتستقبل اختيار المستخدم

enOperationType ReadOperationType()
{
    short OperationType;
    cout << "\n\033[33m[?]\033[0m Choose Operation:\n";
    cout << "    [1] +\n    [2] -\n    [3] *\n    [4] /\n    [5] Mix\n";
    do
    {
        cout << "Enter Choice: ";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);

    return (enOperationType)OperationType;
}

// تختار نوع عملية حسابية بشكل عشوائي عند اختيار وضع "العشوائية"ز

enOperationType GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}

// تنفذ العملية الحسابية المطلوبة بين رقمين لتعطي الناتج الصحيح

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        if (Number2 == 0)
            Number2 = 1;
        return Number1 / Number2;

    default:
        return Number1 + Number2;
    }
}

// تنشئ سؤالاً واحداً بأرقام عشوائية بناءً على المستوى والعملية المختارين

stQuestions GenerateQuestion(enQuizzLevel QuizzLevel, enOperationType OpType)
{
    stQuestions Question;

    if (QuizzLevel == enQuizzLevel::MixLevel)
        QuizzLevel = (enQuizzLevel)RandomNumber(1, 3);

    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;

    Question.QuizzLevel = QuizzLevel;

    switch (QuizzLevel)
    {

    case enQuizzLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;

    case enQuizzLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;

    case enQuizzLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    default:
        break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

    return Question;
}

// تقوم بتوليد جميع أسئلة الاختبار وتخزينها في مصفوفة داخل الهيكل

void GeneratQuizzQuestions(stQuizz &Quizz)
{

    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {

        Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OperationType);
    }
}

// تحول نوع العملية من "رمز برمجي" إلى "نص" لعرضه للمستخدم (مثل + أو -)ر

string GetOperationTypeSymbol(enOperationType OpType)
{

    string arr[] = {"", "+", "-", "x", "/", "Mix"};

    return arr[OpType];
}

// تطبع السؤال الحالي ورقمه على الشاشة بشكل منظم

void PrintTheQestions(stQuizz &Quizz, short QustionsNumber)
{

    cout << "\n\033[36m----------------------------\033[0m\n";

    cout << "Question [" << QustionsNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n";

    cout << "\033[36m----------------------------\033[0m\n";
    cout << "  " << Quizz.QuestionsList[QustionsNumber].Number1 << "\n";

    cout << "  " << Quizz.QuestionsList[QustionsNumber].Number2 << "  " << GetOperationTypeSymbol(Quizz.QuestionsList[QustionsNumber].OperationType) << "\n";

    cout << "-----------\n";
}

// تستقبل إجابة اللاعب من لوحة المفاتيح

int ReadQuestionAnswer()
{
    int Answer = 0;
    cout << "Result: ";
    cin >> Answer;
    return Answer;
}

// تغير لون الشاشة (أخضر للصح، أحمر للخطأ) مع إصدار صوت تنبيه عند الخطأ

void SetScreenColor(bool isRight)
{
    if (isRight)
        cout << "\033[32m";

    else
    {
        cout << "\033[31m";
        cout << "\a";
    }
}

// تقارن إجابة اللاعب بالناتج الصحيح وتحدث إحصائيات الإجابات الصح والخطأ

void CorrectTheQuestionAnswer(stQuizz &Quizz, short QustionsNumber)
{

    if (Quizz.QuestionsList[QustionsNumber].PlayerAnswer != Quizz.QuestionsList[QustionsNumber].CorrectAnswer)
    {
        Quizz.QuestionsList[QustionsNumber].AnswerResult = false;
        Quizz.NumberOfWorngAnswer++;

        SetScreenColor(false);
        cout << "[-] Wrong Answer! :( \n";
        cout << "[*] The Right Answer is: " << Quizz.QuestionsList[QustionsNumber].CorrectAnswer << "\n";
    }

    else
    {
        Quizz.QuestionsList[QustionsNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswer++;
        SetScreenColor(true);
        cout << "[+] Correct Answer! :) \n";
    }

    cout << "\033[0m";
}

// تدير عملية عرض الأسئلة واحداً تلو الآخر وتصحيحها وتحديد حالة النجاح

void AskAndCorrectQuestionsListAnswer(stQuizz &Quizz)
{
    for (short Q = 0; Q < Quizz.NumberOfQuestions; Q++)
    {
        PrintTheQestions(Quizz, Q);
        Quizz.QuestionsList[Q].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, Q);
    }

    Quizz.isPass = (Quizz.NumberOfRightAnswer >= (Quizz.NumberOfQuestions / 2.0));
}

// تعيد نص "PASS" في حال النجاح ونص "FAIL" في حال الرسوب

string GetFinalResultText(bool Pass)
{

    return Pass ? "P A S S" : "F A I L";
}

// تحول مستوى الصعوبة من قيمة رقمية إلى نص مفهوم (Easy, Med...)

string GetQustionsLevelText(enQuizzLevel QuestionLevel)
{

    string arr[] = {"Easy", "Med", "Hard", "Mix"};

    return arr[QuestionLevel - 1];
}

// تطبع ملخص الإحصائيات النهائية للاختبار (عدد الأسئلة، الصح، الخطأ)

void PrintQuizzReults(stQuizz Quizz)
{

    cout << "Questions Total    : " << Quizz.NumberOfQuestions << "\n";
    cout << "Questions Level    : " << GetQustionsLevelText(Quizz.QuestionsLevel) << "\n";
    cout << "Operation Type     : " << GetOperationTypeSymbol(Quizz.OperationType) << "\n";
    cout << "Right Answers      : \033[32m" << Quizz.NumberOfRightAnswer << "\033[0m\n";
    cout << "Wrong Answers      : \033[31m" << Quizz.NumberOfWorngAnswer << "\033[0m\n";
    cout << "--------------------------------------------------\n";
}

// تعرض الشاشة النهائية للنتائج مع الألوان المناسبة لحالة اللاعب

void ShowFinalQuizzScreen(stQuizz Quizz)
{
    ClearScreen();
    string Result = GetFinalResultText(Quizz.isPass);

    if (Quizz.isPass)
        cout << "\033[32m";
    else
        cout << "\033[31m";
    DrawHeader("FINAL RESULTS: " + Result);
    PrintQuizzReults(Quizz);
    cout << "\033[0m";
}
// تمسح الشاشة وتعيد الألوان إلى وضعها الافتراضي

void ClearScreen()
{
    system("clear");
    cout << "\033[0m";
}

// تجمع كل خطوات اللعب في دورة واحدة (إدخال بيانات، توليد أسئلة، عرض النتائج).
void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadQuestionNumber();
    Quizz.QuestionsLevel = ReadQuestionLevel();
    Quizz.OperationType = ReadOperationType();

    GeneratQuizzQuestions(Quizz);
    AskAndCorrectQuestionsListAnswer(Quizz);
    ShowFinalQuizzScreen(Quizz);
}

// الدالة المسؤولة عن بدء اللعبة والسؤال عن الرغبة في اللعب مرة أخرى

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ClearScreen();
        PlayMathGame();
        cout << "\n\033[33m[?]\033[0m Do You Want To Play Again? (Y/N): ";
        cin >> PlayAgain;
        ClearScreen();
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
