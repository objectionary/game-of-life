# SPDX-FileCopyrightText: Copyright (c) 2026 Yegor Bugayenko
# SPDX-License-Identifier: MIT

"""Guard the PDD workflow against moving action references."""

from pathlib import Path
import re
import unittest


class PddWorkflowTest(unittest.TestCase):
    def test_pdd_action_uses_full_commit_sha(self):
        workflow = Path(__file__).resolve().parents[1] / "workflows" / "pdd.yml"
        references = re.findall(
            r"^\s*- uses: volodya-lombrozo/pdd-action@([^\s#]+)",
            workflow.read_text(encoding="utf-8"),
            re.MULTILINE,
        )
        self.assertEqual(len(references), 1, "Expected one PDD action step")
        self.assertRegex(references[0], r"^[0-9a-f]{40}$")


if __name__ == "__main__":
    unittest.main()
