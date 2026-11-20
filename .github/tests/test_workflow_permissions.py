# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT
"""Keep workflow tokens read-only except for explicitly approved job scopes."""

from pathlib import Path
import unittest

import yaml


class WorkflowPermissionsTest(unittest.TestCase):
    def test_least_privilege(self):
        workflows = Path(__file__).resolve().parents[1] / "workflows"
        exceptions = {
            ("actionlint.yml", "actionlint"): {
                "contents": "read",
                "checks": "write",
                "pull-requests": "read",
            },
            ("make.yml", "telegram"): {"actions": "read"},
        }
        files = sorted(workflows.glob("*.yml")) + sorted(workflows.glob("*.yaml"))
        self.assertTrue(files, "No workflows found")
        for path in files:
            with self.subTest(workflow=path.name):
                workflow = yaml.safe_load(path.read_text())
                self.assertEqual(workflow.get("permissions"), {"contents": "read"})
                for name, job in workflow["jobs"].items():
                    with self.subTest(job=name):
                        expected = exceptions.get((path.name, name))
                        self.assertEqual(job.get("permissions"), expected)


if __name__ == "__main__":
    unittest.main()
