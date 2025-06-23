/**
 * @mainpage documentation circular queues
 * 
 * @section introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays
 * 
 * @section operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues
 * - show data / display
 * 
 * @section how to use
 * 1. insert 
 * 2. delete
 * 3. display
 * 4. exit
 * 
 * @author your name (you@domain.com)
 * - nama : maulina khamidah
 * - nim : 20240140221
 * - kelas : E
 * 
 * @brief
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 */
 
#include <iostream>
using namespace std;

/**
 * @class queues
 * @brief this class is for operation queue
 * 
 */
 
class Queues {

    private:
    int FRONT;              /// private variable front for incicate the first element
    int REAR ;             /// private variable rear for indicate the last element
    int max = 5;          /// private variable max for maximum capasity of element
    int queues_array[5]; /// private variable queue_array to store elements

    public:
    /**
     * @brief construct a new queues object
     * set default queues null
     * with front = -1 and rear = -1
     * 
     */

    Queues()     /// constructor untuk mengatur nilai ke rear -1
    {
        FRONT = -1;  /// antrian kosong
        REAR = -1;  
    }

    /**
     * @brief method for entering data into a queue
     * @constructor untuk mengatur nilai ke rear -1
     */

    void insert() {    
        int num;      
        cout << "Enter a number: ";  
        cin >> num;   
        cout << endl;   

        /**
         * @brief Construct 
         * 1. int num menyimpan angka pada num
         * 2. void insert menambahkan element ke dalam antrian queues
         * 3. cout << "Enter a number: untuk menyimpan data pada queues
         * 4. cin >> num menyimpan data pada queues
         * @param FRONT 
         */

        //cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        /**
         * @brief Construct a new if object
         * mengecek apakah antrian sudah penuh
         */

        // cek apakah antrian kosong 
        if (FRONT == max -1) {
             FRONT = 0;
             REAR = 0;
        }
        else {
            // jika REAR berada di posisi terakhir array, kembali ke awal array 
            if (REAR == max -1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }  
        queues_array [REAR] = num;
    }

    void remove() {              /// untuk menghapus elemen antrian dari depan 
        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queues_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
            FRONT = 0;
        else
            FRONT = FRONT + 1;
        
        }
    }

    void display() {         /// untuk menampilkan data pada antrian queues
        int FRONT_position = FRONT;   /// variable
        int REAR_position = REAR;;    /// variable

        //cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empaty\n";
            return;
        }
        cout << "\nElements in the queue are...\n";

        // jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queues_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_position > REAR_position, iterasi dari FRONT  hingga akhir array
            while (FRONT_position <= max -1) {
                cout << queues_array[FRONT_position] << " ";
                FRONT_position++;
            }
            FRONT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queues_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        
    }
};

int main()       /// menampilkan fungsi pada data 
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values"  << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choise (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }
        }
        catch (exception& e)
        {
            cout << "Check for the values entered." << endl;
        }
        
    }
}