#pragma once

#include "Sequences.h"


template<typename T>
class LinkedListSequence : public Sequence<T> {
public:

    LinkedListSequence() : data() {}

    LinkedListSequence<T> *Clone() override { return new LinkedListSequence<T>(); }

    LinkedListSequence<T> *CreateZeroSequence(int count) override {
        return new LinkedListSequence<T>(count);
    }

    LinkedListSequence(T *items, int count) : data(items, count) {}

    LinkedListSequence(int count) : data(count) {}

    //переопределение не охватывает соответствующую функцию из LinkedList,
    // так как требуется общность первого параметра,вследствие чего нет возможности получить данные
    LinkedListSequence<T> *Concat(Sequence<T> *list) {
        for (int i = 0; i < list->GetLength(); ++i) {//добавляю в data все элементы из list,её Size увеличивается
            data.Append(list->Get(i));
        }
        T *items;
        items = (T *) malloc(sizeof(T *) * (data.GetLength() + list->GetLength()));
        for (int i = 0; i < data.GetLength(); ++i) {//записываю все элементы из data  в массив
            items[i] = data.Get(i);
        }

        LinkedListSequence<T> *result = new LinkedListSequence<T>(items, data.GetLength());//создание нового экземпляра
        return result;
    }

    LinkedListSequence(const LinkedList<T> &list) {//конструктор по объекту
        LinkedList<T> *tmp = new LinkedList<T>(list);
        std::cout << "Constructor by object . . .\n";
        data = *tmp;
    }

    LinkedListSequence<T> *GetSubsequence(int startIndex, int endIndex) {//вернуть Sequence<T>*
        LinkedList<T> *tmp = data.GetSubLinkedList(startIndex, endIndex);//создаем экземляр с указанными индексами
        T *items;
        items = (T *) malloc(sizeof(T *) * (endIndex - startIndex));
        for (int i = 0; i < endIndex - startIndex; ++i) {
            items[i] = tmp->Get(i);
        }

        LinkedListSequence<T> *result = new LinkedListSequence<T>(items, endIndex - startIndex);

        return result;
    }

    int GetLength() {
        return data.GetLength();
    }

    T &GetFirst() {
        return data.GetFirst();
    }

    T &GetLast() {
        return data.GetLast();
    }


    T &Get(int index) {
        return data.Get(index);
    }

    void Append(T item) {
        data.Append(item);
    }

    void Prepend(T item) {
        data.Prepend(item);
    }

    void InsertAt(T item, int index) {
        data.InsertAt(item, index);
    }

    void removeAt(int index) {
        data.removeAt(index);
    }

    void Print() {
        data.print_from_begin();
    }

    void BubbleSort(bool(*cmp)(const T &, const T &)) override {
        IBubbleSort<T> obj;
        obj.Sort(cmp, this);
    }

    void QuickSort(bool(*cmp1)(const T &, const T &), bool(*cmp2)(const T &, const T &)) override {
        IQuickSort<T> obj;
        obj.Sort(cmp1, this, cmp2);
    }

    void ShellSort(bool(*cmp)(const T &, const T &)) override {
        IShellSort<T> obj;
        obj.Sort(cmp, this);
    }

private:
    LinkedList<T> data;
};
