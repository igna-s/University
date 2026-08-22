import matplotlib.pyplot as plt
import numpy as np

# Data (Values preserved from your table)
data = np.array([
    [43, 25, 16, 15, 13, 13],   # X
    [13, 14, 4, 5, 4, 3],       # X+
    [9, 17, 5, 9, 11, 14],      # OK-
    [15, 40, 80, 81, 31, 37],   # OK
    [10, 12, 16, 16, 9, 10],    # Perfect P
    [24, 57, 85, 90, 59, 67]    # Global P
])

# English Configuration
row_categories = ['X', 'X+', 'OK-', 'OK', 'Perfect P', 'Global P']
group_columns = ['No Taxonomy', 'With Taxonomy', 'Free', 'Restricted', 'Free', 'Restricted']
colors = ["#FF9C9C", "#FDB873", "#FFFF89", "#A1FAA1", "#88C4FF", "#B68FFF"]

# Plot Setup
x = np.arange(len(group_columns))
width = 0.12

fig, ax = plt.subplots(figsize=(15, 8))

# Create bars for each category
for i, (category, color) in enumerate(zip(row_categories, colors)):
    offset = (i - 2.5) * width
    bars = ax.bar(x + offset, data[i], width,
                    label=category, color=color,
                    edgecolor='black', linewidth=0.5)

    # Add values on top of bars
    for bar, value in zip(bars, data[i]):
        if value > 0:
            height = bar.get_height()
            ax.annotate(f'{value}',
                        xy=(bar.get_x() + bar.get_width()/2, height),
                        xytext=(0, 3),
                        textcoords="offset points",
                        ha='center', va='bottom', fontsize=7, 
                        weight='normal') # Asegura fuente normal

# Vertical divider line
ax.axvline(x=1.5, color='gray', linestyle='--', linewidth=2, alpha=0.7)

# Customization
ax.set_ylabel('Quantity', fontsize=12, weight='normal')
ax.set_title('RAG Strategies Comparison', fontsize=14, weight='normal')
ax.set_xticks(x)
ax.set_xticklabels(group_columns, fontsize=10, weight='normal')
ax.legend(title='Categories', loc='upper left', bbox_to_anchor=(1, 1), prop={'weight': 'normal'})
ax.grid(axis='y', alpha=0.3)
ax.set_axisbelow(True)

# Upper Labels - Normal weight
ax.text(0.5, 100, 'Previous experimental stage', transform=ax.transData, 
        ha='center', va='center', fontsize=12, weight='normal')

ax.text(3.5, 100, 'RAG Architecture', transform=ax.transData, 
        ha='center', va='center', fontsize=12, weight='normal')

# Lower Model Labels - Normal weight
ax.text(2.5, -8, 'Google Gemini Flash-2.5', transform=ax.transData, 
        ha='center', va='top', fontsize=11, weight='normal')

ax.text(4.5, -8, 'OpenAI GPT-OSS 20b', transform=ax.transData, 
        ha='center', va='top', fontsize=11, weight='normal')

# Set Y-axis limits
ax.set_ylim(0, 105)

plt.tight_layout()
plt.subplots_adjust(bottom=0.2, top=0.9)
plt.show()
