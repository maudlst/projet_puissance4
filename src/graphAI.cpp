#include "graphAI.hpp"

using namespace std;

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
                    lsFile << liNumberSon << " " << lwSonsName[liNumberSon] << " " << lvWeightsSon[liNumberSon] << " ";
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
Node& GraphAI::appendChildToParent(Node& psParent, int pnColunm, string pwPositionValue)
{
    Node * lsNodeChild = NULL;
    if(msGraphMap.find(pwPositionValue) != msGraphMap.end()) // Le fils existe deja dans le graphe
    {
        *lsNodeChild = msGraphMap[pwPositionValue];
    }
    else // Le fils n existe pas
    {
        Node lsNewNode(pwPositionValue);
        *lsNodeChild = lsNewNode;
    }
    psParent.addChild(pnColunm,pwPositionValue);
    return *lsNodeChild;
}

/*************   GET and SET    **************/

/*/////////////////////////////////////////////////////////////////////////////
Fonction getPositionName()

Auteur : Généré automatiquement
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

/////////////////////////////////////////////////////////////////////////////*/
map<std::string, Node>& GraphAI::getGraphMap()
{
    return msGraphMap;
}

/*/////////////////////////////////////////////////////////////////////////////
Fonction getPositionName()

Auteur : Généré automatiquement
Nom du projet : Robot Niryo - Puissance 4
Nom du package : AI

/////////////////////////////////////////////////////////////////////////////*/
Node& GraphAI::getRoot()
{
    return msRoot;
}