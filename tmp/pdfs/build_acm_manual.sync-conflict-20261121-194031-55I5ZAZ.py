from pathlib import Path
import re
from xml.sax.saxutils import escape

from reportlab.lib import colors
from reportlab.lib.enums import TA_CENTER
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import mm
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import (
    BaseDocTemplate, Frame, PageTemplate, Paragraph, Spacer, PageBreak,
    Preformatted, Table, TableStyle, KeepTogether, HRFlowable,
)
from reportlab.platypus.tableofcontents import TableOfContents


ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "output" / "pdf" / "ACM区域赛个人代码模板.pdf"
NOTES = ROOT / "笔记"
FONT = Path(r"C:\Windows\Fonts\simhei.ttf")

pdfmetrics.registerFont(TTFont("CN", str(FONT)))
PAGE_W, PAGE_H = A4
INK = colors.HexColor("#17232E")
BLUE = colors.HexColor("#145B73")
TEAL = colors.HexColor("#168078")
MUTED = colors.HexColor("#5E6C75")
PALE = colors.HexColor("#EFF5F5")
CODE_BG = colors.HexColor("#F2F4F5")
RULE = colors.HexColor("#D7E0E3")


styles = getSampleStyleSheet()
styles.add(ParagraphStyle(
    name="TitleCN", fontName="CN", fontSize=25, leading=33,
    textColor=INK, alignment=TA_CENTER, spaceAfter=14,
))
styles.add(ParagraphStyle(
    name="SubtitleCN", fontName="CN", fontSize=11, leading=18,
    textColor=MUTED, alignment=TA_CENTER, spaceAfter=8,
))
styles.add(ParagraphStyle(
    name="H1CN", fontName="CN", fontSize=17, leading=24,
    textColor=BLUE, spaceBefore=12, spaceAfter=8, keepWithNext=True,
))
styles.add(ParagraphStyle(
    name="H2CN", fontName="CN", fontSize=12.5, leading=18,
    textColor=TEAL, spaceBefore=9, spaceAfter=5, keepWithNext=True,
))
styles.add(ParagraphStyle(
    name="H3CN", fontName="CN", fontSize=10.5, leading=15,
    textColor=INK, spaceBefore=6, spaceAfter=3, keepWithNext=True,
))
styles.add(ParagraphStyle(
    name="BodyCN", fontName="CN", fontSize=8.7, leading=13.4,
    textColor=INK, spaceAfter=5, wordWrap="CJK",
))
styles.add(ParagraphStyle(
    name="SmallCN", fontName="CN", fontSize=7.2, leading=10,
    textColor=MUTED, spaceAfter=3, wordWrap="CJK",
))
styles.add(ParagraphStyle(
    name="BulletCN", parent=styles["BodyCN"], leftIndent=12,
    firstLineIndent=-8, spaceAfter=2.5,
))
styles.add(ParagraphStyle(
    name="TableCN", fontName="CN", fontSize=7.4, leading=10.3,
    textColor=INK, wordWrap="CJK",
))
styles.add(ParagraphStyle(
    name="TableHeadCN", fontName="CN", fontSize=7.4, leading=10.3,
    textColor=colors.white, wordWrap="CJK",
))
styles.add(ParagraphStyle(
    name="CodeCN", fontName="CN", fontSize=7.0, leading=9.0,
    textColor=INK, leftIndent=0, rightIndent=0, spaceBefore=0, spaceAfter=0,
))
styles.add(ParagraphStyle(
    name="TOC1CN", fontName="CN", fontSize=9.3, leading=14,
    textColor=BLUE, leftIndent=0, firstLineIndent=0, spaceBefore=2,
))
styles.add(ParagraphStyle(
    name="TOC2CN", fontName="CN", fontSize=8.2, leading=11,
    textColor=INK, leftIndent=14, firstLineIndent=0,
))


def inline_markup(text):
    text = text.strip()
    text = re.sub(r"\[([^\]]+)\]\([^)]*\)", r"\1", text)
    text = escape(text)
    text = re.sub(r"`([^`]+)`", lambda m: "<font name='CN' color='#145B73'>" + m.group(1) + "</font>", text)
    text = re.sub(r"\*\*(.+?)\*\*", r"<b>\1</b>", text)
    text = text.replace("\\|", "&#124;")
    return text


def paragraph(text, style="BodyCN"):
    return Paragraph(inline_markup(text), styles[style])


def is_table_row(line):
    return line.strip().startswith("|") and line.strip().endswith("|")


def split_table_row(line):
    return [cell.strip() for cell in line.strip().strip("|").split("|")]


def add_table(rows, story, width):
    clean = []
    for row in rows:
        cells = split_table_row(row)
        if cells and all(re.fullmatch(r"\s*:?-{3,}:?\s*", c) for c in cells):
            continue
        clean.append(cells)
    if not clean:
        return
    cols = max(map(len, clean))
    data = []
    for ri, row in enumerate(clean):
        row += [""] * (cols - len(row))
        st = "TableHeadCN" if ri == 0 else "TableCN"
        data.append([Paragraph(inline_markup(c), styles[st]) for c in row])
    widths = [width / cols] * cols
    t = Table(data, colWidths=widths, repeatRows=1, hAlign="LEFT")
    t.setStyle(TableStyle([
        ("BACKGROUND", (0, 0), (-1, 0), BLUE),
        ("ROWBACKGROUNDS", (0, 1), (-1, -1), [colors.white, PALE]),
        ("GRID", (0, 0), (-1, -1), 0.35, RULE),
        ("VALIGN", (0, 0), (-1, -1), "TOP"),
        ("LEFTPADDING", (0, 0), (-1, -1), 5),
        ("RIGHTPADDING", (0, 0), (-1, -1), 5),
        ("TOPPADDING", (0, 0), (-1, -1), 4),
        ("BOTTOMPADDING", (0, 0), (-1, -1), 4),
    ]))
    story.extend([t, Spacer(1, 5)])


class ManualDoc(BaseDocTemplate):
    def __init__(self, filename, **kwargs):
        super().__init__(filename, pagesize=A4, **kwargs)
        frame = Frame(17 * mm, 16 * mm, PAGE_W - 34 * mm, PAGE_H - 32 * mm,
                      leftPadding=0, rightPadding=0, topPadding=0, bottomPadding=0,
                      id="normal")
        self.addPageTemplates([PageTemplate(id="main", frames=frame, onPage=self.draw_page)])

    def draw_page(self, canvas, doc):
        canvas.saveState()
        if doc.page > 1:
            canvas.setStrokeColor(RULE)
            canvas.setLineWidth(0.5)
            canvas.line(17 * mm, PAGE_H - 12 * mm, PAGE_W - 17 * mm, PAGE_H - 12 * mm)
            canvas.setFont("CN", 7)
            canvas.setFillColor(MUTED)
            canvas.drawString(17 * mm, PAGE_H - 9.5 * mm, "ACM 区域赛个人代码模板")
            canvas.drawRightString(PAGE_W - 17 * mm, 9 * mm, str(doc.page))
        canvas.restoreState()

    def afterFlowable(self, flowable):
        if isinstance(flowable, Paragraph) and getattr(flowable, "outlineLevel", None) is not None:
            level = flowable.outlineLevel
            text = flowable.getPlainText()
            key = "h-%s-%s" % (self.page, abs(hash(text)))
            self.canv.bookmarkPage(key)
            self.canv.addOutlineEntry(text, key, level=level, closed=False)
            self.notify("TOCEntry", (level, text, self.page, key))


story = []
story.append(Spacer(1, 22 * mm))
story.append(paragraph("ACM 区域赛个人代码模板", "TitleCN"))
story.append(paragraph("基于本仓库练习、训练赛、XCPC 代码与个人算法笔记整理", "SubtitleCN"))
story.append(Spacer(1, 5 * mm))
story.append(HRFlowable(width="56%", thickness=1.5, color=TEAL, hAlign="CENTER"))
story.append(Spacer(1, 8 * mm))
story.append(paragraph("用途", "H2CN"))
story.append(paragraph("比赛中遗忘写法时快速定位：先按目录找到题型，再复制对应的个人代码片段。代码来自仓库中的笔记或源码；说明文字用于提醒适用条件、复杂度和容易写错的边界。", "BodyCN"))
story.append(paragraph("整理规则", "H2CN"))
story.append(paragraph("同主题存在多个版本时，优先参考仓库中修改时间较晚、且已整理成笔记或较新训练/比赛文件中的写法。文件时间受同步与复制影响，作为权重而非正确性证明；冲突文件不纳入模板。题目专属解法只作为思路索引，不能直接当通用模板。", "BodyCN"))
story.append(paragraph("覆盖范围", "H2CN"))
story.append(paragraph("基础输入输出与 STL、二分、差分、单调结构、搜索与图遍历、并查集、筛法、背包 / LIS / 状压 / 树形 DP、KMP、随机异或哈希、线性基、贡献法、位运算及数值 / 几何标准库技巧。", "BodyCN"))
story.append(paragraph("版本线索：最新一批 XCPC 源文件集中在 2026-10-25 至 2026-10-28；新近整理笔记重点覆盖 KMP、图遍历和标准库。以下正文以笔记中的整理版为主，并保留其仓库来源线索。", "SmallCN"))
story.append(Spacer(1, 8 * mm))
story.append(paragraph("阅读说明：`ll` / `i64`、1-based / 0-based、`nxt` / `pi` 等写法按各题原代码语义使用；复制后先核对题目下标、范围和整数上界。", "SmallCN"))
story.append(PageBreak())

toc_title = paragraph("快速目录", "H1CN")
story.append(toc_title)
toc = TableOfContents()
toc.levelStyles = [styles["TOC1CN"], styles["TOC2CN"]]
toc.dotsMinLevel = 0
story.append(toc)
story.append(PageBreak())

story.append(paragraph("仓库代码导航", "H1CN"))
story.append(paragraph("本册正文按算法主题整理。要查看完整题目语境或原始版本，可按下面的路径回到仓库搜索。较新文件用于同类写法的优先参考。", "BodyCN"))
nav_rows = [
    "| 主题 | 仓库线索 |",
    "| --- | --- |",
    "| 基础、STL、搜索、DP、数学 | `笔记/` 中 01-21 主题笔记，详见正文各节来源 |",
    "| BFS / DFS 题目实现 | `study/` 下 P1443、P1596、P1162、CF_1037_D 等；比赛目录内亦有网格与树题 |",
    "| 字符串匹配 | `study/KMP/`；2026-10-21 更新的 KMP 题型总结覆盖普通匹配、差分、删除和自动机 |",
    "| 哈希 | `study/stringHash/`；2026-10-21 随机异或哈希笔记及 `competition/2026CCPCNET/补题/eHash.cpp` |",
    "| XCPC 近期题目 | `XCPC/202AsiaXi'an Regional Contest/`（2026-10-27 至 28）及 `XCPC/2025Universal Cup. Extra Stage 2 Wuhan/`（2026-10-25 至 26） |",
    "| 训练赛 / 竞赛实现 | `competition/` 按比赛目录组织；以题目名检索，结合原题面判断能否复用 |",
]
add_table(nav_rows, story, PAGE_W - 34 * mm)
story.append(paragraph("源文件与时间说明", "H2CN"))
story.append(paragraph("文件路径和题目名用于回查，不能替代题面。仓库同时存在 `copy`、临时文件和同步冲突文件；本册采用已整理的非冲突笔记作为主要代码载体。若较新代码只是题目实现而非通用片段，正文不会把它包装成可直接套用的模板。", "BodyCN"))
story.append(PageBreak())

note_files = sorted(p for p in NOTES.glob("*.md") if ".sync-conflict-" not in p.name and p.name != "README.md")
for note_index, path in enumerate(note_files):
    content = path.read_text(encoding="utf-8-sig")
    lines = content.splitlines()
    story.append(paragraph(escape(path.stem), "H1CN"))
    story[-1].outlineLevel = 0
    source_path = "笔记/" + path.name
    timestamp = path.stat().st_mtime
    from datetime import datetime
    stamp = datetime.fromtimestamp(timestamp).strftime("%Y-%m-%d")
    story.append(paragraph(f"来源：`{source_path}`　|　文件修改时间：{stamp}", "SmallCN"))
    i = 1 if lines and lines[0].startswith("# ") else 0
    while i < len(lines):
        line = lines[i].rstrip()
        if not line.strip():
            i += 1
            continue
        if line.startswith("```"):
            code = []
            i += 1
            while i < len(lines) and not lines[i].startswith("```"):
                code.append(lines[i].expandtabs(4))
                i += 1
            i += 1
            if code:
                block = Preformatted("\n".join(code), styles["CodeCN"], maxLineLength=105, splitChars=" \t,;+-/()[]{}", newLineChars="\n")
                box = Table([[block]], colWidths=[PAGE_W - 34 * mm], hAlign="LEFT")
                box.setStyle(TableStyle([
                    ("BACKGROUND", (0, 0), (-1, -1), CODE_BG),
                    ("BOX", (0, 0), (-1, -1), 0.35, RULE),
                    ("LEFTPADDING", (0, 0), (-1, -1), 7),
                    ("RIGHTPADDING", (0, 0), (-1, -1), 7),
                    ("TOPPADDING", (0, 0), (-1, -1), 6),
                    ("BOTTOMPADDING", (0, 0), (-1, -1), 6),
                ]))
                story.extend([box, Spacer(1, 5)])
            continue
        if line.startswith("|"):
            rows = []
            while i < len(lines) and is_table_row(lines[i]):
                rows.append(lines[i])
                i += 1
            add_table(rows, story, PAGE_W - 34 * mm)
            continue
        hm = re.match(r"^(#{2,3})\s+(.*)$", line)
        if hm:
            level = len(hm.group(1))
            h = paragraph(hm.group(2), "H2CN" if level == 2 else "H3CN")
            h.outlineLevel = 1 if level == 2 else 2
            story.append(h)
            i += 1
            continue
        if line.startswith("---"):
            story.extend([Spacer(1, 2), HRFlowable(width="100%", thickness=0.4, color=RULE), Spacer(1, 4)])
            i += 1
            continue
        if line.startswith("> "):
            story.append(paragraph(line[2:], "SmallCN"))
            i += 1
            continue
        if re.match(r"^\s*[-*]\s+", line):
            body = re.sub(r"^\s*[-*]\s+", "", line)
            story.append(Paragraph("• " + inline_markup(body), styles["BulletCN"]))
            i += 1
            continue
        if re.match(r"^\s*\d+\.\s+", line):
            body = re.sub(r"^\s*\d+\.\s+", "", line)
            story.append(paragraph(body, "BodyCN"))
            i += 1
            continue
        story.append(paragraph(line, "BodyCN"))
        i += 1
    if note_index != len(note_files) - 1:
        story.append(Spacer(1, 5))

story.append(PageBreak())
last_h = paragraph("赛场复用检查", "H1CN")
last_h.outlineLevel = 0
story.append(last_h)
check_rows = [
    "| 先问自己 | 检查内容 |",
    "| --- | --- |",
    "| 下標 | 输入是 0-based 还是 1-based？答案要求哪一种？ |",
    "| 范围 | `int` 是否足够？求和、乘法、差分是否需要 `long long`？ |",
    "| 边界 | 空串、`m==1`、`m>n`、n=0/1、图不连通、重复值是否处理？ |",
    "| 状态 | 多测时容器和全局量是否重置？BFS 入队时是否标记访问？ |",
    "| 单调性 | 二分的 `check` 是否真单调？求最小还是最大可行值？ |",
    "| 复杂度 | 最大输入下时间、空间是否匹配题目限制？ |",
    "| 模板改造 | 源码里的变量范围、字符集、模数、方向和题意是否一致？ |",
]
add_table(check_rows, story, PAGE_W - 34 * mm)
story.append(paragraph("训练集中的答案代码是个人经历的证据，不等同于通用模板。遇到题意相同但范围或状态定义不同时，应先改模型再抄代码。", "BodyCN"))

OUT.parent.mkdir(parents=True, exist_ok=True)
doc = ManualDoc(str(OUT), title="ACM区域赛个人代码模板", author="个人训练仓库整理")
doc.multiBuild(story)
print(OUT)
