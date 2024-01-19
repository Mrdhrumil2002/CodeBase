#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// + = muje pese dene padege
//- = muje pse milenge
void print(map<string, int> mem1)
{ // print the whole map
    map<string, int>::iterator it;
    for (it = mem1.begin(); it != mem1.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    };
    cout << endl;
} // correct
void payment(std::map<string, int> *temp_map, int n)
{ // when someone pay... it will update thier map
    temp_map->at("payment") = temp_map->at("payment") + n;
    map<string, int>::iterator it;
    for (it = temp_map->begin(); it != temp_map->end(); ++it)
    {
        if (it->first != "payment")
        {
            it->second = it->second - n / 5;
        }
    }
}

void hisab(std::map<string, int> *temp_map1, std::map<string, int> *temp_map2, std::map<string, int> *temp_map3, std::map<string, int> *temp_map4, std::map<string, int> *temp_map5, string nameTemp1, string nameTemp2, string nameTemp3, string nameTemp4, string nameTemp5)
{
    temp_map1->at("viprav") = temp_map1->at("viprav") - temp_map2->at("sankalp");
    temp_map1->at("dhrumil") = temp_map1->at("dhrumil") - temp_map3->at("sankalp");
    temp_map1->at("jinhal") = temp_map1->at("jinhal") - temp_map4->at("sankalp");
    temp_map1->at("anjali") = temp_map1->at("anjali") - temp_map5->at("sankalp");

    temp_map2->at("sankalp") = temp_map2->at("sankalp") - temp_map1->at("viprav");
    temp_map2->at("dhrumil") = temp_map2->at("dhrumil") - temp_map3->at("viprav");
    temp_map2->at("jinhal") = temp_map2->at("jinhal") - temp_map4->at("viprav");
    temp_map2->at("anjali") = temp_map2->at("anjali") - temp_map5->at("viprav");

    temp_map3->at("sankalp") = temp_map3->at("sankalp") - temp_map1->at("dhrumil");
    temp_map3->at("viprav") = temp_map3->at("viprav") - temp_map2->at("dhrumil");
    temp_map3->at("jinhal") = temp_map3->at("jinhal") - temp_map4->at("dhrumil");
    temp_map3->at("anjali") = temp_map3->at("anjali") - temp_map5->at("dhrumil");

    temp_map4->at("sankalp") = temp_map4->at("sankalp") - temp_map1->at("jinhal");
    temp_map4->at("viprav") = temp_map4->at("viprav") - temp_map2->at("jinhal");
    temp_map4->at("dhrumil") = temp_map4->at("dhrumil") - temp_map3->at("jinhal");
    temp_map4->at("anjali") = temp_map4->at("anjali") - temp_map5->at("jinhal");

    temp_map5->at("sankalp") = temp_map5->at("sankalp") - temp_map1->at("anjali");
    temp_map5->at("viprav") = temp_map5->at("viprav") - temp_map2->at("anjali");
    temp_map5->at("dhrumil") = temp_map5->at("dhrumil") - temp_map3->at("anjali");
    temp_map5->at("jinhal") = temp_map5->at("jinhal") - temp_map4->at("anjali");

    // store["sankalp"] = temp_map2->at("sankalp") + temp_map3->at("sankalp") + temp_map4->at("sankalp") + temp_map5->at("sankalp");
    // store["viprav"] = temp_map1->at("viprav")  + temp_map3->at("viprav") + temp_map4->at("viprav") + temp_map5->at("viprav");
    // store["dhrumil"] = temp_map1->at("dhrumil") + temp_map2->at("dhrumil") + temp_map4->at("dhrumil") + temp_map5->at("dhrumil");
    // store["jinhal"] = temp_map1->at("jinhal") + temp_map2->at("jinhal") + temp_map3->at("jinhal")  + temp_map5->at("jinhal");
    // store["anjali"] = temp_map1->at("anjali") + temp_map2->at("anjali") + temp_map3->at("anjali") + temp_map4->at("anjali") ;
}
void store(std::map<string, int> *temp_map1, std::map<string, int> *temp_map2, std::map<string, int> *temp_map3, std::map<string, int> *temp_map4, std::map<string, int> *temp_map5)
{
    std::map<string, int> store;
    store["sankalp"] = temp_map2->at("sankalp") + temp_map3->at("sankalp") + temp_map4->at("sankalp") + temp_map5->at("sankalp");
    store["viprav"] = temp_map1->at("viprav") + temp_map3->at("viprav") + temp_map4->at("viprav") + temp_map5->at("viprav");
    store["dhrumil"] = temp_map1->at("dhrumil") + temp_map2->at("dhrumil") + temp_map4->at("dhrumil") + temp_map5->at("dhrumil");
    store["jinhal"] = temp_map1->at("jinhal") + temp_map2->at("jinhal") + temp_map3->at("jinhal") + temp_map5->at("jinhal");
    store["anjali"] = temp_map1->at("anjali") + temp_map2->at("anjali") + temp_map3->at("anjali") + temp_map4->at("anjali");

    return print(store);
}

void countri(std::map<string, int> *temp_map, std::string name)
{ // sankalp.dhrumil.second = sankalp.dhrumil.second - dhrumil.sankalp.second;
    // sankalp.viprav.second = sankalp.viprav.second - viprav.sankalp.second;
    map<string, int>::iterator it;
    for (it = temp_map->begin(); it != temp_map->end(); ++it)
    {
        string namor;
        if (it->first != "payment")
        {
            namor = it->first;
            it->second = it->second + 5;
        };
    };
}
// ek function je be be na group banave
// for example pela sankalp nu jovie too hve su thase ke

// sankalp { viprav: -70   viprav{ sankalp : -200
//         dhrumil :               dhrumil :
//         anjali:                 anjali:
//         jinhal: }               jinhal: }
// to have apde viprav ma sankalp gotvanu
// ne ene sankalp na hisab ma minus kar devanu

// sankalp(viprav) = sankalp.viprav - viprav.sankalp
// sankalp(dhrumil) = sankalp.dhrumil - dhrumil.sankalp
// sankalp(jinhal) = sankalp.jinhal - jinhal.sankalp
// sankalp(anjali) = sankalp.anjali - anjali.sankalp

int main()
{

    map<string, int> sankalp;
    map<string, int> viprav;
    map<string, int> dhrumil;
    map<string, int> jinhal;
    map<string, int> anjali;

    sankalp["payment"] = 0;
    sankalp["viprav"] = 0;
    sankalp["dhrumil"] = 0;
    sankalp["anjali"] = 0;
    sankalp["jinhal"] = 0;

    viprav["payment"] = 0;
    viprav["sankalp"] = 0;
    viprav["dhrumil"] = 0;
    viprav["anjali"] = 0;
    viprav["jinhal"] = 0;

    dhrumil["payment"] = 0;
    dhrumil["viprav"] = 0;
    dhrumil["sankalp"] = 0;
    dhrumil["anjali"] = 0;
    dhrumil["jinhal"] = 0;
    dhrumil["prathamraj"] = 0;
    dhrumil["isha"] = 0;

    jinhal["payment"] = 0;
    jinhal["viprav"] = 0;
    jinhal["dhrumil"] = 0;
    jinhal["anjali"] = 0;
    jinhal["sankalp"] = 0;

    anjali["payment"] = 0;
    anjali["viprav"] = 0;
    anjali["dhrumil"] = 0;
    anjali["sankalp"] = 0;
    anjali["jinhal"] = 0;

    /* //   sankalp pays 50 rs;
        //   dhrumil pays 300rs
        //   jinhal pays 1000rs
        //   viprav pays 100rs
        //   sankalp pays 80

        // payment one ; sankalp pays 50 rs;
        // sankalp.payment = 50;
        // sankalp.anjali = -sankalp.payment / 5;
        // sankalp.dhrumil = -sankalp.payment / 5;
        // sankalp.viprav = -sankalp.payment / 5;
        // sankalp.jinhal = -sankalp.payment / 5;

        // // payment two ; dhrumil pays 300rs
        // dhrumil.payment = 300;
        // dhrumil.anjali = -dhrumil.payment / 5;
        // dhrumil.sankalp = -dhrumil.payment / 5;
        // dhrumil.viprav = -dhrumil.payment / 5;
        // dhrumil.jinhal = -dhrumil.payment / 5;
     */
    payment(&dhrumil, 90);
    payment(&dhrumil, 100);
    payment(&jinhal, 500);
    // payment(&dhrumil, 350);
    // payment(&viprav, 360);
    // store(&sankalp, &viprav, &dhrumil, &jinhal, &anjali);

    hisab(&sankalp, &viprav, &dhrumil, &jinhal, &anjali, "sankalp", "viprav", "dhrumil", "jinhal", "anjali");
    print(dhrumil);
    cout << "end sucessfully";
    return 0;
}