#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct poly
{
    int coef;
    int degre;
    struct poly *suiv;
};

typedef struct poly *polynome;

polynome CreePolynome_vide(int N, polynome Tete)
{
    polynome P, Q = NULL;
    int k = N;

    for (int i = 0; i <= k; i++)
    {
        P = (struct poly *)malloc(sizeof(struct poly));
        if (i == 0)
        {
            P->degre = N;
            N--;
            Q = P;
            Tete = P;
        }
        else
        {
            P->degre = N;
            N--;
            Q->suiv = P;
            Q = P;
        }
        P->suiv = NULL;
    }
    return Tete; // Return the updated head
}

polynome LirePoly(int N, polynome Tete)
{
    polynome P;
    Tete = CreePolynome_vide(N, Tete);
    P = Tete;
    while (P != NULL)
    {
        printf("Donnez le coeficient de degree %d :", P->degre);
        scanf("%d", &P->coef);
        P = P->suiv;
    }
    return Tete;
}

void AffichPoly(polynome Tete)
{
    printf(" P(X) = ");

    while (Tete != NULL)
    {
        if (Tete->degre == 0)
        {
            printf("%d", Tete->coef);
            Tete = Tete->suiv;
        }
        else if (Tete->degre == 1)
        {
            if (Tete->coef == 1)
            {
                printf("X + ");
            }
            else
            {
                printf("%d*X + ", Tete->coef);
                Tete = Tete->suiv;
            }
        }
        else if (Tete->coef == 1)
        {
            printf("X^%d + ", Tete->degre);
            Tete = Tete->suiv;
        }
        else if (Tete->coef == 0)
        {
            Tete = Tete->suiv;
        }
        else
        {
            printf("%d*X^%d + ", Tete->coef, Tete->degre);
            Tete = Tete->suiv;
        }
    }
}

float EvaluePoly(polynome Pol, float x)
{
    float result = 0;
    while (Pol != NULL)
    {
        result = result + Pol->coef * pow(x, Pol->degre);
        Pol = Pol->suiv;
    }
    printf("\n\t\tP(%.2f) = %.2f\n\n", x, result);
    return result;
}

polynome SomePoly(polynome P1, polynome P2)
{
    polynome Tete, P3 = NULL;
    if ((P1->degre) > (P2->degre))
    {
        Tete = CreePolynome_vide(P1->degre, P3);
    }
    else
    {
        Tete = CreePolynome_vide(P2->degre, P3);
    }
    P3 = Tete; // Update P3 to point to the head of Tete
    while (P3 != NULL)
    {
        if ((P1->degre) > (P2->degre))
        {
            P3->coef = P1->coef;
            P1 = P1->suiv;
        }
        else if ((P1->degre) < (P2->degre))
        {
            P3->coef = P2->coef;
            P2 = P2->suiv;
        }
        else
        {
            P3->coef = P1->coef + P2->coef;
            P1 = P1->suiv;
            P2 = P2->suiv;
        }
        P3 = P3->suiv;
    }
    return Tete; // Return the head of the resulting polynomial
}

int main()
{
    int N, L;

    printf("Donnez le Nombre Degre de polynom 1:");
    scanf("%d", &N);
    polynome T1 = NULL;
    T1 = LirePoly(N, T1);
    AffichPoly(T1);

    printf("\n\nDonnez le Nombre Degre de polynom 2:");
    scanf("%d", &L);
    polynome T2 = NULL;
    T2 = LirePoly(L, T2);
    AffichPoly(T2);

    printf("\n\t\t le Polymom 3 est : ");
    polynome T3;
    T3 = SomePoly(T1, T2);
    AffichPoly(T3);

    return 0;
}
