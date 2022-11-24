#include "graphAI.hpp"

using namespace std;


void GraphAI::exportToFile() //ecriture
{
    ofstream lsFile(FILE_NAME);  //Ouverture en ecriture du fichier
    Node lsCurrentNode;
    map<string, Node>::iterator liMapIterator;
    int liNumberSon;
    int *lvWeightsSon;
    string *lwSonsName;
    int lnSize;

    if(lsFile)
    {
        // On s'occupe d'abord de la racine (premiere ligne du fichier)
        lsFile << msRoot.getPositionName() << " ";
        lvWeightsSon = msRoot.getWeights();
        lwSonsName = msRoot.getChildren();
        lnSize = (sizeof(lvWeightsSon) / sizeof(int));
        for(liNumberSon = 0; liNumberSon < lnSize; liNumberSon++)
        {
            if(lvWeightsSon[liNumberSon] >=  0)
            {
                lsFile << liNumberSon << " " << lwSonsName[liNumberSon] << " " << lvWeightsSon[liNumberSon] << " ";
            }
            else // ne rien faire
            {}
        }
        lsFile << endl;

        //On s'occupe ensuite des autres noeuds du graphe
        for(liMapIterator = msGraphMap.begin(); liMapIterator != msGraphMap.end(); liMapIterator++)
        {
            lsCurrentNode = liMapIterator -> second;
            
            lsFile << lsCurrentNode.getPositionName() << " ";
            lvWeightsSon = lsCurrentNode.getWeights();
            lwSonsName = lsCurrentNode.getChildren();
            lnSize = (sizeof(lvWeightsSon) / sizeof(int));

            for(liNumberSon = 0; liNumberSon < lnSize; liNumberSon++)
            {
                if(lvWeightsSon[liNumberSon] >=  0)
                {
                    lsFile << liNumberSon << " " << lwSonsName[liNumberSon] << " " <<  lvWeightsSon[liNumberSon] << " ";
                }
                else // ne rien faire
                {}
            }
            lsFile << endl;
        }
    }
    else // Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en ecriture" << endl;
    }
}


void GraphAI::importFromFile()//lecture
{
    ifstream lsFile(FILE_NAME);
    Node lsCurrentNode;
    int liIndex;
    vector<string> lvLineCuts;
    string *lvSonsName;
    int *lvWeightsSons;
    string lwLine;
    string lwNodeName;

    if(lsFile)
    {
        //Traitement de la racine
        getline(lsFile, lwLine);
        lvLineCuts = cutString(lwLine,' ');
        Node lsCurrentNode(lvLineCuts[0]);
        lvSonsName = lsCurrentNode.getChildren();
        lvWeightsSons = lsCurrentNode.getWeights();

        for(liIndex = 1; liIndex < lvLineCuts.size(); liIndex+= 3)
        {
            lvSonsName[liIndex] = lvLineCuts[liIndex + 1];
            lvWeightsSons[liIndex] = stoi(lvLineCuts[liIndex + 2]);
        }
        msRoot = lsCurrentNode;

        //Traitement des autres noeuds
        while(getline(lsFile, lwLine)){
            lvLineCuts = cutString(lwLine,' ');
            Node lsCurrentNode(lvLineCuts[0]);
            lvSonsName = lsCurrentNode.getChildren();
            lvWeightsSons = lsCurrentNode.getWeights();

            for(liIndex = 1; liIndex < lvLineCuts.size(); liIndex+= 3)
            {
                lvSonsName[liIndex] = lvLineCuts[liIndex + 1];
                lvWeightsSons[liIndex] = stoi(lvLineCuts[liIndex + 2]);
            }
            msGraphMap.insert(pair<string, Node>(lvLineCuts[0], lsCurrentNode));
        }        
    }
    else 
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
    }


}

vector<string> GraphAI::cutString(string pwLine, char pwDelimiter)
{
    vector<string> lvLineCuts;
    stringstream lwStringStream(pwLine);
    string lwPieceOfLine;
    while (getline(lwStringStream, lwPieceOfLine, pwDelimiter))
    {
        lvLineCuts.push_back(lwPieceOfLine);
    }

    return lvLineCuts;
}

/*************   GET and SET    **************/


map<std::string, Node>& GraphAI::getGraphMap()
{
    return msGraphMap;
}

Node& GraphAI::getRoot()
{
    return msRoot;
}