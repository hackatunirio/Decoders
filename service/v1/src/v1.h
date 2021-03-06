#pragma once

#include <ngrest/common/Service.h>
#include "../../../model/data.h"
#include "profile.h"

using namespace adopt_a_freshman;

//! API version 1
/*! MVP implementation of "Adote um calouro!!!". */
// *location: api/v1
class v1: public ngrest::Service
{
public:
    
    //! Login
    /*! Login and take a token. */
    // *method: POST
    // *location: login/{username}/{password}
    std::string Login(const string& username, const string& pasword);

    //! Subscribe
    /*! Subscribe on system. */
    // *method: POST
    // *location: profile
    std::string Subscribe(const UserRegistry &registy, int token);

    //! Choose recreation
    /*! Update the recreation intrests. */
    // *method: PUT
    // *location: recreations
    std::string ChooseRecreation(const list<string> & choices, int token);

    //! Choose enterteinment
    /*! Update the entertainment intrests. */
    // *method: PUT
    // *location: entertainments
    std::string ChooseEntertainment(const list<string> & choices, int token);

    //! Choose disciplines
    /*! Update the discipline intrests. */
    // *method: PUT
    // *location: disciplines
    std::string ChooseDisciplines(const list<string> & choices, int token);

    //! Edit profile
    /*! Update the profile. */
    // *method: PUT
    // *location: profile
    std::string UpdateProfile(const Profile & profile, int token);

    //! Get a profile
    /*! Get profile information. */
    // *method: GET
    // *location: profile
    service::Profile GetProfile(const std::string & username, int token); 

    //! Get a veterans
    /*! Get veterans information sorted by matching with freshman profile. */
    // *method: GET
    // *location: veterans
    list<Profile> GetVeterans(int token);

    //! Request adopt a freshman
    // *method: POST
    // *location: adoption_request_by_veteran
    bool AdoptFreshmanRequest(const string & username, int token);

    //! Request adoption to veteran
    /*! Request veteran adoption. */
    // *method: POST
    // *location: adoption_request_by_freshman
    bool AddAdoptionRequest(const std::string & username, int token);

    //! Finalize adoption.
    /*! Request veteran adoption. */
    // *method: POST
    // *location: adoption
    bool ConfirmeAdoption(const std::string & username, int token);

    //! Finalize adoption.
    /*! Request veteran adoption. */
    // *method: POST
    // *location: adoption
    bool BugReport(const Report & report, int token);

};


