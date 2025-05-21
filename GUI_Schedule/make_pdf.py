import pandas as pd
from reportlab.lib import colors
from reportlab.lib.pagesizes import landscape, LETTER
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle


def do_work():
    # Load data and normalize
    df = pd.read_csv("/home/turjo-pop/Documents/Make_Schedule/Algorithm/build/schedule.csv")
    df.columns = df.columns.str.strip()
    df['Day'] = df['Day'].astype(str).str.strip().str.lower()
    df['Year'] = df['Year'].astype(str).str.strip()

    # Debug: check actual unique values
    print("Unique Days:", df['Day'].unique())
    print("Unique Years:", df['Year'].unique())

    # Use actual days from file, sorted manually if needed
    weekdays = df['Day'].unique()
    years = sorted(df['Year'].unique())
    time_slots = list(df.columns[2:])

    # Assign color per year
    year_colors = {
        year: color for year, color in zip(years, [
            colors.red, colors.blue, colors.green, colors.orange
        ])
    }

    # Table data
    table_data = [["Day", "Year"] + time_slots]
    row_styles = []
    row_index = 1

    for day in weekdays:
        day_data = df[df['Day'] == day]

        for i, year in enumerate(years):
            year_data = day_data[day_data['Year'] == year]
            if not year_data.empty:
                row = [day.capitalize() if i == 0 else "", year]
                row += [str(year_data[col].values[0]) if pd.notna(year_data[col].values[0]) else "" for col in time_slots]
                table_data.append(row)
                row_styles.append(('TEXTCOLOR', (0, row_index), (-1, row_index), year_colors[year]))
                row_index += 1

    # Create table
    doc = SimpleDocTemplate("final_schedule.pdf", pagesize=landscape(LETTER))
    t = Table(table_data, repeatRows=1)

    # Merge weekday cells (first column)
    merge_commands = []
    row = 1
    for day in weekdays:
        merge_commands.append(('SPAN', (0, row), (0, row + len(years) - 1)))
        row += len(years)

    # Table style
    style = TableStyle([
                           ('GRID', (0, 0), (-1, -1), 0.4, colors.grey),
                           ('BACKGROUND', (0, 0), (-1, 0), colors.whitesmoke),
                           ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                           ('ALIGN', (0, 0), (-1, 0), 'CENTER'),
                           ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'),
                       ] + row_styles + merge_commands)

    t.setStyle(style)
    doc.build([t])
if __name__ == "__main__":
    do_work()
    # print("File2 is being run directly")