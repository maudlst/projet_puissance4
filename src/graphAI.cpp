#include "graphAI.hpp"

using namespace std;

GraphAI::GraphAI()
{

}

/*/////////////////////////////////////////////////////////////////////////////
Fonction exportToFile()

Auteur : Maud Lestienne (IATIC-4)
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

But de la fonction :
  Charge dans un fichier l'état de l'IA

/////////////////////////////////////////////////////////////////////////////*/
void GraphAI::exportToFile() //ecriture
{
    ofstream lsFile(FILE_NAME);  //Ouverture en ecriture du fichier
    Node *lsCurrentNode;
    map<string, Node *>::iterator liMapIterator;
    int liNumberSon;
    string *lwSonsName;
    int lnSize;

    if(lsFile)
    {
        // On s'occupe d'abord de la racine (premiere ligne du fichier)
        //Ecriture du nom du noeud racine
        lsFile << msRoot->getPositionName() << " ";
        cout << msRoot->getPositionName() << " ";
        
        lwSonsName = msRoot->getChildren();
        lnSize = 5;
        //Pour chaque fils existant ont ecrit son indice dans le tableau de fils et son nom
        for(liNumberSon = 0; liNumberSon < lnSize; liNumberSon++)
        {
            if(lwSonsName[liNumberSon] != "")
            {
                lsFile << liNumberSon << " " << lwSonsName[liNumberSon] << " ";
                cout << liNumberSon << " " << lwSonsName[liNumberSon] << " ";
            }
            else // ne rien faire
            {}
        }
        lsFile << endl;
        cout << endl;

        //On s'occupe ensuite des autres noeuds du graphe
        for(liMapIterator = msGraphMap.begin(); liMapIterator != msGraphMap.end(); liMapIterator++)
        {
            lsCurrentNode = liMapIterator -> second;
            //Ecriture du nom du noeud coourant et de ses informations concernant son poids
            lsFile << lsCurrentNode->getPositionName() << " ";
            cout << lsCurrentNode->getPositionName() << " ";
            lsFile << lsCurrentNode->getWeight().mnGamePlayed << " "  << lsCurrentNode->getWeight().mnGameWon << " " << lsCurrentNode->getWeight().mnVictoryRate << " ";
            cout << lsCurrentNode->getWeight().mnGamePlayed << " "  << lsCurrentNode->getWeight().mnGameWon << " " << lsCurrentNode->getWeight().mnVictoryRate << " ";
            
            lwSonsName = lsCurrentNode->getChildren();
            lnSize = 5;
            //Pour chaque fils existant ont ecrit son indice dans le tableau de fils et son nom
            for(liNumberSon = 0; liNumberSon < lnSize; liNumberSon++)
            {
                if(lwSonsName[liNumberSon] != "")
                {
                    lsFile << liNumberSon << " " << lwSonsName[liNumberSon] << " ";
                    cout << liNumberSon << " " << lwSonsName[liNumberSon] << " ";
                }
                else // ne rien faire
                {}
            }
            lsFile << endl;
            cout << endl;
        }
    }
    else // Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en ecriture" << endl;
    }
}

/*/////////////////////////////////////////////////////////////////////////////
Fonction importFromFile()

Auteur : Maud Lestienne (IATIC-4)
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

But de la fonction :
  Récupère l'état de l'IA depuis un fichier

/////////////////////////////////////////////////////////////////////////////*/
void GraphAI::importFromFile()//lecture
{
    ifstream lsFile(FILE_NAME);
    int liIndex;
    vector<string> lvLineCuts;
    string *lvSonsName;
    string lwLine;
    string lwNodeName;

    if(lsFile)
    {
        //Traitement de la racine
        getline(lsFile, lwLine);
        lvLineCuts = cutString(lwLine,' ');

        for(liIndex = 1; liIndex < (int)lvLineCuts.size(); liIndex+= 2)
        {
            msRoot->getChildren()[stoi(lvLineCuts[liIndex])] = lvLineCuts[liIndex + 1];
            cout << stoi(lvLineCuts[liIndex]) << " " << lvLineCuts[liIndex + 1] << " ";
        }
        cout << msRoot->getPositionName() << " " << endl;
        //Traitement des autres noeuds
        while(getline(lsFile, lwLine)){
            lvLineCuts = cutString(lwLine,' ');
            Node lsCurrentNode(lvLineCuts[0]);
            lsCurrentNode.setWeight(stoi(lvLineCuts[1]), stoi(lvLineCuts[2]), stof(lvLineCuts[3]));
            lvSonsName = lsCurrentNode.getChildren();

            for(liIndex = 4; liIndex < (int)lvLineCuts.size(); liIndex+= 2)
            {
                lvSonsName[stoi(lvLineCuts[liIndex])] = lvLineCuts[liIndex + 1];
                cout << stoi(lvLineCuts[liIndex]) << " " << lvLineCuts[liIndex + 1] << " ";
                
            }
            msGraphMap[lvLineCuts[0]] = &lsCurrentNode;
            cout << endl;
        }        
    }
    else 
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
    }
}
/*/////////////////////////////////////////////////////////////////////////////
Fonction cutString()

Auteur : Maud Lestienne (IATIC-4)
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

But de la fonction :
  Découpe une ligne selon un délimiteur en retirant les retours à la ligne 

Entrées :
  pwLine : La ligne à découpée
  pwDelimiter : Le caractère qui va permettre de découper la chaîne

Sorties : 
  lvLineCuts : le vecteur qui contient chaque bout de string couper

/////////////////////////////////////////////////////////////////////////////*/
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

/*/////////////////////////////////////////////////////////////////////////////
Fonction appendChildToParent()

Auteur : Arnaud HENCHES (IATIC-4)
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

But de la fonction :
  Découpe une ligne selon un délimiteur en retirant les retours à la ligne 

Entrées :
  psParent : Le père 
  pnColunm : La colonne qui va permettre de passer du père au fils
  pwPositionValue : la valeur de la position du fils 

Sorties : 
  lsNodeChild : la structure Node du fils

/////////////////////////////////////////////////////////////////////////////*/
Node *GraphAI::appendChildToParent(Node *psParent, int pnColunm, string pwPositionValue)
{
    psParent->addChild(pnColunm,pwPositionValue);
    if(msGraphMap.find(pwPositionValue) == msGraphMap.end()) // Le fils n'existe pas dans le graphe
    {
        msGraphMap[pwPositionValue] = new Node(pwPositionValue);
        return msGraphMap[pwPositionValue];
    }
    else // Le fils existe déja
    {
        return msGraphMap[pwPositionValue];
    }
}

/*************   GET and SET    **************/

/*/////////////////////////////////////////////////////////////////////////////
Fonction getPositionName()

Auteur : Généré automatiquement
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

/////////////////////////////////////////////////////////////////////////////*/
map<std::string, Node *>& GraphAI::getGraphMap()
{
    return msGraphMap;
}

/*/////////////////////////////////////////////////////////////////////////////
Fonction getPositionName()

Auteur : Généré automatiquement
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

/////////////////////////////////////////////////////////////////////////////*/
Node *GraphAI::getRoot()
{
    return msRoot;
}
/*
void GraphAI::setRoot(Node& psNode)
{
    msRoot = psNode;
}
*/

void GraphAI::addNodetoMap(Node *psNode)
{
    msGraphMap[psNode->getPositionName()] = psNode;
}
