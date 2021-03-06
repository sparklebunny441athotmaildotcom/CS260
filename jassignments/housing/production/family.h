#ifndef FAMILY_H
#define FAMILY_H
#include<iostream>
using namespace std;

class family
{

    private:
        char *FID;
        char *familyName;
        int memberCount;
        char *familyFriend1;
        char *familyFriend2;
        char *familyFriend3;
        family * nextFamily = nullptr;
        int whichOne = 0;

    public:
        family();
        family(const char* newFID, const char* newName, const int& newMembers);
        family(const family& otherFamily);
        const family& operator=(const family& otherFamily);
        friend std::ostream& operator<<(std::ostream& out, const family& thisFamily);
        ~family();

        const char* getFID();
        const char* getFamilyName();
        const int getMemberCount();
        char* getF1();
        char* getF2();
        char* getF3();
        family * getNextFamily();


        bool addFriend(const char* friendFID);
        void setFID(const char* familyID);
        void setFamilyName(const char* newFamilyName);
        void setMemberCount(const int& howMany);
        void setF1(const char* friend1);
        void setF2(const char* friend2);
        void setF3(const char* friend3);
        void setNextFamily(family*& nextLink);
        
};

#endif
