#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex g_mutex;  //Declaración global de Mutex
bool g_ready = false; //Declaración de variable global es un indicador para notificar al otro subproceso "Terminé mi parte"
int g_data = 0;  //Declaración de variable global, es el búfer de tamaño único para almacenar datos

int produceData() {
  int randomNumber = rand() % 10; //Genera un número aleatorio
  cout << "Produce dato: " << randomNumber << "\n";
  return randomNumber;
}

void consumeData(int data) { cout << "Recibe(consume) el dato: " << data << "\n"; }

// función de subproceso de consumidor
void consumer() {
  while (true) {
    while (!g_ready) {
      // sleep por 1 segundos
      this_thread::sleep_for (chrono::seconds(1));
    }
    unique_lock<mutex> ul(g_mutex); //unique_lock es un contenedor RAII para std::mutex. Obtiene los beneficios de RAII: bloquea automáticamente el mutex en construcción y lo desbloquea cuando se destruye
    consumeData(g_data);
    g_ready = false;
  }
}

// Produce thread de función
void producer() {
  while (true) {
    unique_lock<std::mutex> ul(g_mutex);

    g_data = produceData();
    g_ready = true;
    ul.unlock();
    while (g_ready) {
      // sleep por 2 segundos
      this_thread::sleep_for (chrono::seconds(1));
    }
  }
}

void consumerThread() { consumer(); }

void producerThread() { producer(); }

int main() {
  thread t1(consumerThread);
  thread t2(producerThread);
  t1.join();
  t2.join();
  return 0;
}