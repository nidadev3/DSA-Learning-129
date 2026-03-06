using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace BankingSystem.Models
{
    class CurrentAccount : Account
    {
        public CurrentAccount(int accountId, string name, uint permissions)
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

            if (amount > balance)
            {
                Console.WriteLine("Insufficient balance.");
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

