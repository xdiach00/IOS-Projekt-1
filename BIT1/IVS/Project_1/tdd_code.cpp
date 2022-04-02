//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Mikhail Diachenko <xdiach00@stud.fit.vutbr.cz>
// $Date:       $2022-03-06
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Mikhail Diachenko
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"


PriorityQueue::PriorityQueue()
{
    m_pHead = NULL;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *currentElement = GetHead();
    size_t len = Length();

    if (len == 0) {
        delete currentElement, len;

        return;
    } else if (len == 1) {
        delete m_pHead, currentElement, len;

        return;
    } else {
        for (int i = 0; i < len; i++) {
            m_pHead = m_pHead->pNext;
        }

        delete m_pHead, currentElement, len;
    }
    
    return;
}

void PriorityQueue::Insert(int value)
{
    if (m_pHead == NULL) {
        m_pHead = new Element_t {
            .pNext = NULL,
            .value = value
        };
    } else if (m_pHead->pNext == NULL) {
        if (m_pHead->value > value) {
            m_pHead->pNext = new Element_t {
                .pNext = m_pHead->pNext,
                .value = value
            };
        } else {
            m_pHead->pNext = new Element_t {
                .pNext = m_pHead->pNext,
                .value = m_pHead->value
            };
            m_pHead->value = value;
        }
    } else {
        Element_t *currentElement = GetHead();
        
        while (currentElement != NULL) {
            if (currentElement->value < value) {
                currentElement->pNext = new Element_t {
                    .pNext = currentElement->pNext,
                    .value = currentElement->value
                };
                currentElement->value = value;

                return;
            } else if (currentElement->pNext == NULL) {
                currentElement->pNext = new Element_t {
                    .pNext = currentElement->pNext,
                    .value = value
                };

                return;
            }else {
                currentElement = currentElement->pNext;
            }
        }
    }
}

bool PriorityQueue::Remove(int value)
{
    Element_t *currentElement = GetHead();
    

    if (Element_t *needElement = Find(value)) {
        if (currentElement->pNext == NULL) {
            m_pHead = NULL;

            delete needElement;
            return true;
        } else if (currentElement == needElement) {
            m_pHead = currentElement->pNext;

            delete needElement;
            return true;
        } else {
            while (currentElement->pNext != NULL) {
                if (currentElement->pNext == needElement) {
                    currentElement->pNext = needElement->pNext;

                    delete needElement;
                    return true;
                }
                currentElement = currentElement->pNext;
            }
        }

        delete needElement;
    }
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    Element_t *currentElement = GetHead();
    size_t len = Length(), i = 0;

    while (currentElement != NULL) {
        if (currentElement->value == value) {

            return currentElement;
        }
        currentElement = currentElement->pNext;
    }
    return NULL;
}

size_t PriorityQueue::Length()
{
	Element_t *currentElement = GetHead();
    size_t i = 0;

    while (currentElement != NULL) {
        i++;
        currentElement = currentElement->pNext;
    }
    return i;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return m_pHead;
}

/*** Konec souboru tdd_code.cpp ***/
