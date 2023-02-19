#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel
{
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
protected:
    string OwnerName;
    int ContentQuality;
public:
    YoutubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
    }

    void GetInfo(){
        cout << "Name:" << Name << endl;
        cout << "OwnerName:" << OwnerName << endl;
        cout << "SubscribersCount:" << SubscribersCount << endl;
        cout << "Videos:" << endl;
        for (string videoTitle : PublishedVideoTitles)
        {
            cout << videoTitle << endl;
        }

        
    }
    void Subscribe(){
        SubscribersCount++;
    }
    void Unsubscribe(){
        if(SubscribersCount>0)
            SubscribersCount--;
    }
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);


    }
    void CheckAnalytics(){
        if(ContentQuality<5)
            cout << Name << " has a bad quality content." << endl;
            else
            cout << Name << " has a good quality content." << endl;
    }
};

class CookingYoutubeChannel:public YoutubeChannel {
public:
    CookingYoutubeChannel(string name, string ownerName): YoutubeChannel(name, ownerName){

    }
    void Practice(){
        cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        ContentQuality++;
    }
};
class SingersYoutubeChannel : public YoutubeChannel
{
public:
    SingersYoutubeChannel(string name, string ownerName): YoutubeChannel(name, ownerName){

    }
    void Practice(){
        cout << OwnerName << " is taking singing classes, learning new songs, learning how to dance..." << endl;
        ContentQuality++;
    }
};
int main()
{

    CookingYoutubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    cookingYtChannel=CookingYoutubeChannel("Amy's Kitchen", "Amy");

    SingersYoutubeChannel singersYtChannel("JohnSings", "John");

    // cookingYtChannel.PublishVideo("Apple Pie");
    // cookingYtChannel.PublishVideo("Chocolate Cake");
    // cookingYtChannel.Subscribe();
    // cookingYtChannel.Subscribe();
    // singersYtChannel.GetInfo();
    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    
    YoutubeChannel *yt1 = &cookingYtChannel;
    YoutubeChannel *yt2 = &singersYtChannel;

    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    /*
        YoutubeChannel ytChannel("MG", "Mohamed Ghareeb");
        ytChannel.PublishVideo("C++ for beginners");
        ytChannel.PublishVideo("Python for Pros");
        ytChannel.PublishVideo("ROS Intro");
        // ytChannel.Subscribe();
        // ytChannel.Subscribe();
        // ytChannel.Subscribe();
        // ytChannel.Subscribe();
        ytChannel.Unsubscribe();

        // YoutubeChannel ytChannel2("AmySings", "Amy");

        ytChannel.GetInfo();
        // ytChannel2.GetInfo();
        // ytChannel.Name = "MG";
        // ytChannel.OwnerName = "MohamedGhareeb";
        // ytChannel.SubscribersCount = 1800;
        // ytChannel.PublishedVideoTitles = {"C++ for beginners Video 1", "HTML & CSS Video 1", "C++ OOP Video 1"};

        // cout << "Name:" << ytChannel.Name << endl;
        // cout << "OwnerName:" << ytChannel.OwnerName << endl;
        // cout << "SubscribersCount:" << ytChannel.SubscribersCount << endl;
        // cout << "Videos:" << endl;
        // for (string videoTitle : ytChannel.PublishedVideoTitles)
        // {
        //     cout << videoTitle << endl;
        // }

        // ytChannel2.Name = "AmySings";
        // ytChannel2.OwnerName = "Amy";
        // ytChannel2.SubscribersCount = 2000;
        // ytChannel2.PublishedVideoTitles = {"Johny B - Cover", "Maps - Cover"};

        // cout << "Name:" << ytChannel2.Name << endl;
        // cout << "OwnerName:" << ytChannel2.OwnerName << endl;
        // cout << "SubscribersCount:" << ytChannel2.SubscribersCount << endl;
        // cout << "Videos:" << endl;
        // for (string videoTitle : ytChannel2.PublishedVideoTitles)
        // {
        //     cout << videoTitle << endl;
        // }
    */    
}
