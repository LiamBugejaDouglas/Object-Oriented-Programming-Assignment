#include <iostream>
#include <tuple>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class Vertex{

    private:

        const T data;
        vector<shared_ptr<Vertex>> connected;

    public:

        //Used to move ownership
        Vertex(const T& dt):data(std::move(dt)){

        }

        //Returns data of specific vertex
        const T& getData(){

            return data;
        }

        //Returns list of pointers of connected vertices
        std::vector<shared_ptr<Vertex<T>>>& getConnected(){

            return connected;
        }

        //Adds a pointer to list of connected vertices of a vertex
        void addToConnected(shared_ptr<Vertex<T>>& connectedPtr){

            connected.insert(connected.begin(), connectedPtr);
        }

        //Removes a pointer from a list of connected vertcies of a certex
        void removeFromConnected(const T& data){

            for(size_t i=0 ;i<connected.size(); i++){

                if(connected[i]->getData()==data){

                    connected.erase(connected.begin() + i);
                }
            }
        }

        //Prints a vertex and the connected vertices to it
        void printVertex(){

            std::cout<< data <<": ";

            for(auto connect : connected){

                cout << "[" << connect->getData() << "]";
            }

            std::cout<<endl;
        }
};

template <typename T>
class graph{

    private:

        vector<shared_ptr<Vertex<T>>> DAG;

    public:

        //Returns a pointer of a specific vertex
        shared_ptr<Vertex<T>>& getVertexPtr(const T& value) {

            for (auto& vertex : DAG) {

                if (vertex->getData() == value) {

                    return vertex;
                }
            }
            //If not found sends a static pointer
            static shared_ptr<Vertex<T>> unkown;
            return unkown;
        }

        //Deletes vertex from DAG
        void removeVertex(const T& data){

            for(size_t i=0; i<DAG.size(); i++){
                if(DAG[i]->getData()==data){

                    DAG.erase(DAG.begin() + i);
                }

                //Deletes the vertex in connected list 
                DAG[i]->removeFromConnected(data);
            }
        }

        graph(std::vector<std::tuple<T, T>>& links){

            for(auto& link : links){

                //Moving ownership from vertex class to the graph class
                T leftVertex = std::move(std::get<0>(link));
                T rightVertex = std::move(std::get<1>(link));

                //Updating the pointers of the values
                shared_ptr<Vertex<T>> leftVertexPtr = getVertexPtr(leftVertex);
                shared_ptr<Vertex<T>> rightVertexPtr = getVertexPtr(rightVertex);

                //Check if vertex exists
                if(!leftVertexPtr){

                    //Creating vertex and inserting it at the end of the DAG 
                    DAG.insert(DAG.end(), make_shared<Vertex<T>>(leftVertex));
                    //Update pointer
                    leftVertexPtr = getVertexPtr(leftVertex);
                }

                if(!rightVertexPtr){

                    DAG.insert(DAG.end(), make_shared<Vertex<T>>(rightVertex));
                    rightVertexPtr = getVertexPtr(rightVertex);
                }

                //Adding right vertex to connected vector of the left vertex
                leftVertexPtr->addToConnected(rightVertexPtr);
            }
        }

        //Prints all the vertices with the vector of connected
        void printDAG(){

            std::cout<<"---DAG---"<<endl;

            for(auto vertex : DAG){
                
                //Calling print method from Vertex class
                vertex->printVertex();
            }

            std::cout<<"---------"<<endl;
        }
};

int main() {

    //Creating link vector that accepts int values
    std::vector<std::tuple<int, int>> link1;
    
    //Inserting int values in link2
    link1.push_back( std::make_tuple(1, 2));
    link1.push_back( std::make_tuple(1, 3));
    link1.push_back( std::make_tuple(1, 4));
    link1.push_back( std::make_tuple(3, 5));
    link1.push_back( std::make_tuple(3, 6)); 
    link1.push_back( std::make_tuple(6, 7));
    link1.push_back( std::make_tuple(6, 8)); 
    //Checking if cycle is detected
    link1.push_back( std::make_tuple(5, 1)); 

    //Creating DAG using vector link2
    graph<int> g1(link1);

    //Using methods in DAG class

    g1.printDAG();

    g1.removeVertex(5);

    g1.printDAG();

    //Creating link vector that accepts char values
    std::vector<std::tuple<char, char>> link2;
    
    //Inserting char values in link1
    link2.push_back(std::make_tuple('a','b'));
    link2.push_back(std::make_tuple('a','c'));
    link2.push_back(std::make_tuple('c','d'));
    link2.push_back(std::make_tuple('b','e'));
    link2.push_back(std::make_tuple('e','f')); 
    link1.push_back(std::make_tuple('e','g'));
    //Checking if cycle is detected
    link2.push_back(std::make_tuple('d','a')); 

    //Creating DAG using vector link1
    graph<char> g2(link2);

    //Using methods in the DAG class

    g2.printDAG();

    g2.removeVertex('d');

    g2.printDAG();

}