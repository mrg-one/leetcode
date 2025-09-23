class Spreadsheet {

    private data: Map<string, number>;

    constructor(rows: number) {
        this.data = new Map<string, number>();
    }

    setCell(cell: string, value: number): void {
        this.data.set(cell, value);
    }

    resetCell(cell: string): void {
        this.data.delete(cell);
        
    }

    getValue(formula: string): number {

        const parts = formula.replace("=", "").split(/([\+\-\*\/])/);
        const n1 = this.isCellReference(parts[0]) ? this.getCellValue(parts[0]) : parseInt(parts[0]);
        const n2 = this.isCellReference(parts[2]) ? this.getCellValue(parts[2]) : parseInt(parts[2]);
        const operator = parts[1];
        switch (operator) {
            case "+":
                return n1 + n2;
            case "-":
                return n1 - n2;
            case "*":
                return n1 * n2;
            case "/":
                return n1 / n2;
            default:
                throw new Error("Invalid operator");
        }
    }

    isCellReference(token: string): boolean {
        return /^[A-Z]+[0-9]+$/.test(token);
    }

    getCellValue(cell: string): number {
        return this.data.get(cell) || 0;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * var obj = new Spreadsheet(rows)
 * obj.setCell(cell,value)
 * obj.resetCell(cell)
 * var param_3 = obj.getValue(formula)
 */