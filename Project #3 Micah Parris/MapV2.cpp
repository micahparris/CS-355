#include "MapV2.h"

void MapV2::makeItem()
{
    string xstr;
    while(nextToken != "</item>"){ // <ptype>
        

        if(nextToken == "<basic>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            makeBasicItem();
        }
        else if(nextToken == "<consume>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            makeConsumeItem();
        }
        else if (nextToken == "<use>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
           makeUseItem();
        }
        else{
            cout<<"Item Parse Error Location 2"<<endl;
            ifderr = true;
            break;
        }
        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</area>

    //add area to vector
    //mapItems.push_back(itemPtr);
} //end makeItem()


void MapV2::makeBasicItem()
{
    string xstr;
    Item* i = new Item;
    i->setType("basic");
    while(nextToken != "</basic>"){ // <ptype>
        if(nextToken == "<name>"){
            parser.eatToken();
            nextToken = parser.getNext();
            i->setName(nextToken); 
        }
        else if(nextToken == "<desc>"){
            parser.eatToken();
            nextToken = parser.getNext();
            i->setDesc(nextToken);
        }
        else if (nextToken == "<star>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr);
            i->setSR(atoi(xstr.c_str()));
        }
        else if(nextToken == "</desc>" || nextToken == "</name>" || nextToken == "</star>"){
            //do nothing
        }
        else{
            cout<<"Item Parse Error Location 2"<<endl;
            ifderr = true;
            break;
        }

        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</area>

    //add area to vector
    mapItems.push_back(i);
}




void MapV2::makeConsumeItem()
{
    Effect* effect = new Effect;
    Item* c = new ConsumeItem();
    c->setType("consume");
    string xstr;
    while(nextToken != "</consume>"){ // <ptype>
        
        if(nextToken == "<name>"){
            parser.eatToken();
            nextToken = parser.getNext();
            c->setName(nextToken); 
        }
        else if(nextToken == "<desc>"){
            parser.eatToken();
            nextToken = parser.getNext();
            c->setDesc(nextToken);
        }
        else if (nextToken == "<star>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr);
            c->setSR(atoi(xstr.c_str()));
        }
        else if (nextToken == "<actmess>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            c->setActiveMessage(nextToken);
        }
        else if (nextToken == "<actar>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr);
            c->setActiveArea(atoi(xstr.c_str()));
        }
        else if (nextToken == "<effect>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr, ',');
            effect->effectID = atoi(xstr.c_str());
            getline(ss, xstr, ',');
            effect->effectAmt = atoi(xstr.c_str());
            c->addEffect(effect);
        }
        else if(nextToken == "</desc>" || nextToken == "</name>" || nextToken == "</star>" || nextToken == "</actmess>" || nextToken == "</actar>" || nextToken == "</effect>"){
            //do nothing
        }
        else{
            cout<<"Cosume parse error"<<endl;
            ifderr = true;
            break;
        }

        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</area>

    //add consume item to vector
    mapItems.push_back(c);
}



void MapV2::makeUseItem()
{
    Item* u = new UseItem();
    u->setType("use");
    string xstr;
    while(nextToken != "</use>"){ // <ptype>
        
        if(nextToken == "<name>"){
            parser.eatToken();
            nextToken = parser.getNext();
            u->setName(nextToken); 
        }
        else if(nextToken == "<desc>"){
            parser.eatToken();
            nextToken = parser.getNext();
            u->setDesc(nextToken);
        }
        else if (nextToken == "<star>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr);
            u->setSR(atoi(xstr.c_str()));
        }
        else if (nextToken == "<actmess>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            u->setActiveMessage(nextToken);
        }
        else if (nextToken == "<actar>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr);
            u->setActiveArea(atoi(xstr.c_str()));
        }
        else if (nextToken == "<rule>")
        {
            
            parser.eatToken();
            nextToken = parser.getNext();
            Rule* r = new Rule;

            istringstream ss(nextToken);
            getline(ss, xstr, ',');
            r->beginRm = atoi(xstr.c_str());
            getline(ss, xstr, ',');
            r->direction = xstr[0];
            getline(ss, xstr, ',');
            r->destRm = atoi(xstr.c_str());
            u->addRule(r);
        }
        else if(nextToken == "</desc>" || nextToken == "</name>" || nextToken == "</star>" || nextToken == "</actmess>" || nextToken == "</actar>" || nextToken == "</rule>"){
            //do nothing
        }
        else{
            cout<<"Use item parse error"<<endl;
            ifderr = true;
            break;
        }

        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</area>

    //add consume item to vector
    mapItems.push_back(u);
}



void MapV2::makePlayer()
{
    string playerType;

    while(nextToken != "</ptype>"){ // <ptype>
        if(nextToken == "hpsp"){
            //parser.eatToken();
            //nextToken = parser.getNext();
            mainPlayer = new HPSP;
        }
        else if(nextToken == "basic"){
            //parser.eatToken();
            //nextToken = parser.getNext();
            mainPlayer = new BasicPlayer;
        }
        else 
        {
            cout << "ERROR MAKING PLAYER" << endl;
            ifderr = true;
            break;
        }
        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</area>
}

Player* MapV2::getPlayer()
{
    return mainPlayer;
}



void MapV2::buildMap()
{
    ifderr = false;
    parser.tokenIt();

    nextToken = parser.getNext();

    if(nextToken == "<game>"){
        parser.eatToken();
        nextToken = parser.getNext();
        while(nextToken != "</game>"){  //consider what happens when run out of tokens && not error state
            if(nextToken == "<area>"){
                parser.eatToken();
                nextToken = parser.getNext();
                makeArea();
            }
            else if(nextToken == "<links>"){
                parser.eatToken();
                nextToken = parser.getNext();
                makeLinks();
            }
            else if (nextToken == "<item>")
            {
                parser.eatToken();
                nextToken = parser.getNext();
                makeItem();
            }
            else if (nextToken == "<ptype>")
            {
                parser.eatToken();
                nextToken = parser.getNext();
                makePlayer();
            }
            else{
                cout<<"Parse Error Location 1"<<endl;
                ifderr = true;
                break;
            }
            parser.eatToken();
            nextToken = parser.getNext();
        }// while !</game>

        if(ifderr){
            cout<<" :: ERROR :: IF Document Formatting Error"<<endl;
            cout<<"Game Loading Failed"<<endl;
            cout<<"General Area of Parsing Failure:"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<nextToken<<endl;
            parser.eatToken();
            nextToken = parser.getNext();
            cout << nextToken << endl;
            parser.eatToken();
            nextToken = parser.getNext();
            cout<<nextToken<<endl;
            parser.eatToken();
            nextToken = parser.getNext();
            cout<<nextToken<<endl;
            cout<<"-------------------------------------"<<endl;
            return;
        }
    }
    else{
        cout<<" :: ERROR :: No \"<game>\" tag found."<<endl;
        cout<<"Game Loading Failed"<<endl;
    }

    //link up areas
    linkLinks();
    cout << "Before insert Items" << endl;
    insertItems();
    cout << "After insert items" << endl;
}


void MapV2::resetItems()
{
    for (int i = 0; i < areasVec.size(); i++) 
    {
        areasVec[i]->info.areaItems.destroyList();
    }
}


ostream& operator<<(ostream& osObject, MapV2& map)
{
	osObject<<"******************************************************************"<<endl;
	osObject<<"CHEATING!!!! Printing the set of areas and connections on the map."<<endl;
	osObject<<"******************************************************************"<<endl;
	for(int i=0; i<map.areasVec.size(); i++){
		cout<<"This is area: "<<i+1<<endl;
		cout<<map.areasVec[i]->info.getDescription()<<endl;
		if(map.areasVec[i]->info.getID() == 1){
			cout<<"Area is INSTADEATH."<<endl;
		}
		if(map.areasVec[i]->info.getGoal() == 1){
			cout<<"Area is GOAL."<<endl;
		}
		cout<<"Connections:"<<endl;
		cout<<"\t u: Area #"<<map.reverseLookUp(map.areasVec[i]->u)<<endl;
		cout<<"\t d: Area #"<<map.reverseLookUp(map.areasVec[i]->d)<<endl;
		cout<<"\t l: Area #"<<map.reverseLookUp(map.areasVec[i]->l)<<endl;
		cout<<"\t r: Area #"<<map.reverseLookUp(map.areasVec[i]->r)<<endl;
	}
    osObject<<"******************************************************************"<<endl;
	osObject<<"CHEATING!!!! ITEM LOCATIONS."<<endl;
	osObject<<"******************************************************************"<<endl;
	for (int i = 0; i < map.areasVec.size(); i++)
    {
        osObject << "Items for area: " << i + 1 << map.areasVec[i]->info.getDescription() << endl;
        map.areasVec[i]->info.areaItems.printNames();
    }

	return osObject;
}

void MapV2::insertItems()
{
    for (int i = 0; i < mapItems.size(); i++) 
    {
        areasVec[mapItems[i]->getSR() -1]->info.areaItems.insertLast(mapItems[i]);
    }
}