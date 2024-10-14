#include <iostream>
#include <string>
using namespace std;
void startAdventure();
void forestPath();
void encounterDragon();
void findTreasure();
void mountainPath();
void magicalCave();
void solvePuzzle();
void villageEncounter();
void chooseAdventure();
void meetOldWizard();
void dragonRiddle();
void helpVillagers();
void learnPotionMaking();
void choosePotion();
void continueAdventure();
int main(){
    cout<<"Mystical Forest Adventure mein aapka khush aamdeed!"<<endl;
    cout<<"==========================================="<<endl;
    startAdventure();
    return 0;
}
void startAdventure(){
    char choice;
    cout<<"\nAap ek khoobsurat clearing mein hain, jo lambe darakhton aur rangeen phoolon se ghiri hui hai."<<endl;
    cout<<"Aap baayein taraf ja sakte hain jo ke ajib forest path (L) hai ya daayein taraf jo ke rocky mountain (R) hai."<<endl;
    cout<<"Enter L ya R: ";
    while(true){
        cin>>choice;
        if(choice=='L'||choice=='l'){
            forestPath();
            break;
        }
		else if(choice=='R'||choice=='r'){
            mountainPath();
            break;
        }
		else{
            cout<<"Galat choice. Meherbani karke L ya R daakhil karein: ";
        }
    }
}
void forestPath(){
    char choice;
    cout<<"\nAap forest path par chal rahe hain, patton ki awaz sunte hue."<<endl;
    cout<<"Achaanak, aap ek bade dragon se samna karte hain jo ek pathar par baitha hai!"<<endl;
    cout<<"Kya aap (F)ighting karna chahte hain, (R)un away karna chahte hain, ya (C)all for help karna chahte hain?"<<endl;
    cout<<"Enter F, R, ya C: ";
    while(true){
        cin>>choice;
        if(choice=='F'||choice=='f'){
            encounterDragon();
            break;
        }
		else if(choice=='R'||choice=='r'){
            cout<<"\nAap mehfooz taur par daud kar clearing mein wapas aa jaate hain, aapka dil tezi se dhadak raha hai."<<endl;
            startAdventure();
            break;
        }
		else if(choice=='C'||choice=='c'){
            meetOldWizard();
            break;
        }
		else{
            cout<<"Galat choice. Meherbani karke F, R, ya C daakhil karein: ";
        }
    }
}
void encounterDragon() {
    char choice;

    cout<<"\nDragon shor machata hai, aag aate hue!"<<endl;
    cout<<"Kya aap (T)ry to negotiate karna chahte hain ya (S)wing your sword karna chahte hain?"<<endl;
    cout<<"Enter T ya S: ";

    // Input validation loop
    while(true) {
        cin>>choice;
        if(choice=='T'||choice=='t') {
            cout<<"\nAap himmat se dragon ki taraf aate hain aur negotiate karne ki koshish karte hain."<<endl;
            cout<<"Aapki hairani ke liye, dragon baat karne par razi hota hai! Aap dosto ban jaate hain."<<endl;
            cout<<"Aap dono mil kar treasure cave ko explore karte hain."<<endl;
            findTreasure();
            break;
        } else if(choice=='S'||choice=='s') {
            cout<<"\nAap apni talwar uthate hain, lekin dragon bahut taqatwar hai!"<<endl;
            cout<<"Uski shor se aap haar jaate hain. Game khatam!"<<endl;
            return;
        } else {
            cout<<"Galat choice. Meherbani karke T ya S daakhil karein: ";
        }
    }
}

void findTreasure(){
    cout<<"\nAap aur dragon treasure cave mein ghus jaate hain, jo sona aur gehne se bhara hai!"<<endl;
    cout<<"Mubarak ho! Aapne game jeet li hai!"<<endl;
    cout<<"Aap cave se khushi aur nai dosti ke saath nikalte hain!"<<endl;
    cout<<"Khelne ke liye shukriya!"<<endl;
}
void mountainPath(){
    char choice;
    cout<<"\nAap rocky mountain ki taraf ja rahe hain, thandi hawa aapke chehre par mehsoos hoti hai."<<endl;
    cout<<"Jab aap mountain ke paon par pahunchte hain, aapko ek glowing cave dikhayi deti hai."<<endl;
    cout<<"Kya aap (E)nter karna chahte hain ya (R)eturn karna chahte hain?"<<endl;
    cout<<"Enter E ya R: ";
    while(true){
        cin>>choice;
        if(choice=='E'||choice=='e'){
            magicalCave();
            break;
        }
		else if(choice=='R'||choice=='r'){
            cout<<"\nAap clearing ki taraf wapas aate hain, mountain ki raaz ke bare mein sochte hue."<<endl;
            startAdventure();
            break;
        }
		else{
            cout<<"Galat choice. Meherbani karke E ya R daakhil karein: ";
        }
    }
}
void magicalCave(){
    char choice;
    cout<<"\nAap cave mein kadam rakhte hain, aur jadoo ki roshni aapko gher leti hai."<<endl;
    cout<<"Andar, aapko ek chamakdar crystal aur potions ka chest nazar aata hai."<<endl;
    cout<<"Kya aap (T)ake the crystal lena chahte hain, (O)pen the chest karna chahte hain, ya (L)eave the cave karna chahte hain?"<<endl;
    cout<<"Enter T, O, ya L: ";
    while(true) {
        cin>>choice;
        if(choice=='T'||choice=='t'){
            cout<<"\nAap crystal uthate hain, aur ye aapko wisdom aur taqat deta hai!"<<endl;
            cout<<"Aap cave se nikalte hain, zyada confident aur knowledgeable mehsoos karte hue."<<endl;
            cout<<"Mubarak ho! Aapne game jeet li hai!"<<endl;
            cout<<"Khelne ke liye shukriya!"<<endl;
            return;
        }
		else if(choice=='O'||choice=='o'){
            cout<<"\nAap chest kholte hain aur potions paate hain jo aapko mukhtalif abilities dete hain."<<endl;
            cout<<"Aap jadoo aur potions ke maharat bana jaate hain!"<<endl;
            cout<<"Mubarak ho! Aapne game jeet li hai!"<<endl;
            cout<<"Khelne ke liye shukriya!"<<endl;
            return;
        }
		else if(choice=='L'||choice=='l'){
            cout<<"\nAap cave se bahar nikalte hain, sochte hue ke aapne kya khazana chhoda hoga."<<endl;
            villageEncounter();
            break;
        }
		else{
            cout<<"Galat choice. Meherbani karke T, O, ya L daakhil karein: ";
        }
    }
}
void villageEncounter(){
    char choice;
    cout<<"\nJab aap cave se door jaate hain, aapko ek choti si gaon dikhayi deti hai."<<endl;
    cout<<"Gaon walay pareshan lag rahe hain. Wo batate hain ke ek monster unke crops chura raha hai!"<<endl;
    cout<<"Kya aap (H)elp karna chahte hain ya (C)ontinue karna chahte hain?"<<endl;
    cout<<"Enter H ya C: ";
    while(true){
        cin>>choice;
        if(choice=='H'||choice=='h'){
            helpVillagers();
            break;
        }
		else if(choice=='C'||choice=='c'){
            cout<<"\nAap apne adventure ko jaari rakhte hain, gaon walon ko unki mushkilat mein chhodte hain."<<endl;
            startAdventure();
            break;
        }
		else{
            cout<<"Galat choice. Meherbani karke H ya C daakhil karein: ";
        }
    }
}
void helpVillagers(){
    char choice;
    cout<<"\nGaon walon ki madad karne ke liye, aapko monster ka samna karna hoga!"<<endl;
    cout<<"Kya aap (T)alk to the villagers karna chahte hain ya (F)ight the monster seedha karna chahte hain?"<<endl;
    cout<<"Enter T ya F: ";
    while(true){
        cin>>choice;
        if(choice=='T'||choice=='t'){
            cout<<"\nGaon wale aapko monster ke baare mein jankari dete hain aur aap tayyari karte hain."<<endl;
            cout<<"Aap monster se milte hain aur aapki bravery aur samajhdaari se usay hara dete hain!"<<endl;
            cout<<"Mubarak ho! Aapne gaon ko bacha liya!"<<endl;
            cout<<"Khelne ke liye shukriya!"<<endl;
            return;
        }
		else if(choice=='F'||choice=='f'){
            cout<<"\nAap seedha monster se ladte hain, lekin wo taqatwar hai!"<<endl;
            cout<<"Aap haar jaate hain. Game khatam!"<<endl;
            return;
        }
		else{
            cout<<"Galat choice. Meherbani karke T ya F daakhil karein: ";
        }
    }
}
void meetOldWizard(){
    char choice;
    cout<<"\nAap ek purane wizard se milte hain jo aapko ek paheli deta hai."<<endl;
    cout<<"Agar aap ise sahi jawab dete hain, wo aapki madad karega."<<endl;
    cout<<"Paheli hai: 'Main aisa hoon jo aap dekhte hain, lekin kabhi nahi chhute.' Kya hai?"<<endl;
    cout<<"Enter your answer: ";
    string answer;
    cin>>answer;
    if(answer=="shadow"){
        cout<<"\nAapne sahi jawab diya! Wizard aapko ek magic potion deta hai."<<endl;
        cout<<"Ab aap apne adventure ko jaari rakh sakte hain."<<endl;
        continueAdventure();
    }
	else{
        cout<<"\nWizard ne sir hila diya. 'Galat!'"<<endl;
        cout<<"Aap wizard se door chalte hain aur apne akele kaam karte hain."<<endl;
        cout<<"Game over!"<<endl;
    }
}
void continueAdventure() {
    cout<<"\nAap kya karna chahte hain? Aapka adventure aapka intezar kar raha hai!"<<endl;
    startAdventure();
}