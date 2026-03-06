using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankingSystem.Models
{
    class SavingsAccount : Account
    {
        public SavingsAccount(int accountId, string name, uint permissions)
            : base(accountId, name, permissions)
        {
        }

        public override void Deposit(double amount)
        {
            if (!CanDeposit())
            {
                Console.WriteLine("Deposit not allowed.");
                return;
            }

            if (amount <= 0)
            {
                Console.WriteLine("Invalid amount.");
                return;
            }

            balance += amount;
            AddTransaction(amount);
        }

        public override void Withdraw(double amount)
        {
            if (!CanWithdraw())
            {
                Console.WriteLine("Withdraw not allowed.");
                return;
            }

            if (balance - amount < 500)
            {
                Console.WriteLine("Minimum balance must remain 500.");
                return;
            }

            balance -= amount;
            AddTransaction(-amount);
        }

        public override void SaveToFile()
        {
        }

        public override void LoadFromFile()
        {
        }
    }
}



