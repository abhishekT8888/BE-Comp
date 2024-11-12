// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract CustomerData {
    
    // Structure to hold customer data
    struct Customer {
        uint id;
        string name;
        string email;
        uint balance;
    }

    // Array to store customers
    Customer[] public customers;
    uint public customerCount = 0;

    // Function to add a new customer
    function addCustomer(string memory _name, string memory _email, uint _balance) public {
        customerCount++;
        customers.push(Customer(customerCount, _name, _email, _balance));
    }

    // Function to retrieve customer data by ID
    function getCustomer(uint _id) public view returns (uint, string memory, string memory, uint) {
        require(_id > 0 && _id <= customerCount, "Customer ID is invalid");
        Customer memory cust = customers[_id - 1]; // Array is 0-indexed
        return (cust.id, cust.name, cust.email, cust.balance);
    }

    // Fallback function - reverts any call with invalid function
    fallback() external payable {
        revert("This contract does not accept direct payments");
    }

    // Receive function (optional, if you want to handle Ether)
    receive() external payable {
        // Logic to handle Ether (if required)
    }
}
